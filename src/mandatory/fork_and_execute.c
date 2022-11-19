/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:52:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/19 13:37:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fork_and_execute.h"

void	execute_cmd(t_arg_set *set, int level)
{
	static int	fd[2];
	pid_t		pid;

	if (level == set->cmd_cnt)
		return ;
	determine_io_fd(set, fd, level);
	pid = fork();
	if (pid < 0)
		handle_error("pipex: fork failed", PERROR);
	else if (pid == 0)
		run_child_process(set, fd[0], level);
	close(set->cmds[level]->io_fd[0]);
	close(set->cmds[level]->io_fd[1]);
	execute_cmd(set, level + 1);
	if (wait(NULL) == -1)
		handle_error("pipex: wait failed", PERROR);
}

void	determine_io_fd(t_arg_set *set, int fd[2], int level)
{
	if (level == 0)
	{
		pipe(fd);
		set->cmds[0]->io_fd[0] = set->file[0];
		set->cmds[0]->io_fd[1] = fd[1];
	}
	else if (level == (set->cmd_cnt - 1))
	{
		set->cmds[level]->io_fd[0] = fd[0];
		set->cmds[level]->io_fd[1] = set->file[1];
	}
	else
	{
		set->cmds[level]->io_fd[0] = fd[0];
		pipe(fd);
		set->cmds[level]->io_fd[1] = fd[1];
	}
}

void	run_child_process(t_arg_set *set, int read_fd, int lev)
{
	if ((lev == 0 && set->file[0] < 0) || \
		((lev == set->cmd_cnt - 1) && set->file[1] < 0))
		exit(1);
	if (set->cmds[lev]->cmd == 0)
	{
		if (set->cmds[lev]->cmd_arg[0] && \
			ft_strchr(set->cmds[lev]->cmd_arg[0], '/'))
			printf_std_err(NOFILEDIR, set->cmds[lev]->cmd_arg[0], "\n");
		else
			printf_std_err(NOCMD, set->cmds[lev]->cmd_arg[0], "\n");
		exit(1);
	}
	do_dup2(set->cmds[lev]->io_fd);
	close(read_fd);
	execve(set->cmds[lev]->cmd, set->cmds[lev]->cmd_arg, set->envp);
	handle_error("pipex: execve failed", PERROR);
}

void	do_dup2(int io_fd[2])
{
	int	res;

	res = dup2(io_fd[0], STDIN_FILENO);
	if (res == -1)
		handle_error("pipex: dup2 error 0", PERROR);
	close(io_fd[0]);
	res = dup2(io_fd[1], STDOUT_FILENO);
	if (res == -1)
		handle_error("pipex: dup2 error 1", PERROR);
	close(io_fd[1]);
}
