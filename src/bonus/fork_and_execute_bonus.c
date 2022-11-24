/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:52:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/24 15:39:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_and_execute_bonus.h"

void	execute_cmd(t_arg_set *set, int lev)
{
	static int		fd[2];
	pid_t			pid;

	if (lev == set->cmd_cnt)
		return ;
	determine_io_fd(set, fd, lev);
	pid = fork();
	if (pid < 0)
		handle_error("pipex: fork failed", PERROR);
	else if (pid == 0)
		run_child_process(set, fd[0], lev);
	close(set->io_fd[0]);
	close(set->io_fd[1]);
	execute_cmd(set, lev + 1);
	if (lev == (set->cmd_cnt - 1) && waitpid(pid, &set->stat, 0) == -1)
		handle_error("pipex: wait failed", PERROR);
	else if (lev != (set->cmd_cnt -1) && wait(NULL) == -1)
		handle_error("pipex: wait failed", PERROR);
}

void	determine_io_fd(t_arg_set *set, int fd[2], int lev)
{
	if (lev == 0)
	{
		set->io_fd[0] = open_io_files(set->in, set->is_heredoc, INPUT);
		pipe(fd);
		set->io_fd[1] = fd[1];
	}
	else if (lev == (set->cmd_cnt - 1))
	{
		set->io_fd[0] = fd[0];
		set->io_fd[1] = open_io_files(set->out, set->is_heredoc, OUTPUT);
	}
	else
	{
		set->io_fd[0] = fd[0];
		pipe(fd);
		set->io_fd[1] = fd[1];
	}
}

void	run_child_process(t_arg_set *set, int read_fd, int lev)
{
	if ((lev == 0 && set->io_fd[0] < 0) || \
		(lev == (set->cmd_cnt - 1) && set->io_fd[1] < 0))
		exit(1);
	if (set->cmds[lev]->cmd == 0)
	{
		if (set->cmds[lev]->args[0] && \
			ft_strchr(set->cmds[lev]->args[0], '/'))
		{
			printf_std_err(NOFILEDIR, set->cmds[lev]->args[0], "\n");
			exit(126);
		}
		printf_std_err(NOCMD, set->cmds[lev]->args[0], "\n");
		exit(127);
	}
	do_dup2(set->io_fd);
	close(read_fd);
	execve(set->cmds[lev]->cmd, set->cmds[lev]->args, set->envp);
	handle_error("pipex: execve failed", PERROR);
}

void	do_dup2(int io_fd[2])
{
	int	res;

	res = dup2(io_fd[0], STDIN_FILENO);
	if (res == -1)
		handle_error("pipex: dup2 error", PERROR);
	close(io_fd[0]);
	res = dup2(io_fd[1], STDOUT_FILENO);
	if (res == -1)
		handle_error("pipex: dup2 error", PERROR);
	close(io_fd[1]);
}

int	open_io_files(char *file, int is_heredoc, int file_type)
{
	int	fd;

	fd = 0;
	if (file_type == INPUT)
	{
		fd = open(file, O_RDONLY);
		if (is_heredoc)
			unlink(file);
	}
	else if (file_type == OUTPUT)
	{
		if (is_heredoc)
			fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (fd < 0)
		printf_std_err(NOFILEDIR, file, "\n");
	return (fd);
}
