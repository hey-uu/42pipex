/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:52:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:08:22 by hyeyukim         ###   ########.fr       */
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
		handle_error("fork failed", PERROR);
	else if (pid == 0)
		run_child_process(set, fd[0], level);
	if (level != (set->cmd_cnt - 1))
		close(set->cmds[level]->io_fd[1]);
	close(set->cmds[level]->io_fd[0]);
	execute_cmd(set, level + 1);
	if (wait(NULL) == -1)
		handle_error("wait failed", PERROR);
}

void	determine_io_fd(t_arg_set *set, int fd[2], int level)
{
	if (level == 0)
	{
		if (pipe(fd) == -1)
			handle_error("pipe failed", PERROR);
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
		if (pipe(fd) == -1)
			handle_error("pipe failed", PERROR);
		set->cmds[level]->io_fd[1] = fd[1];
	}
}

void	run_child_process(t_arg_set *set, int read_fd, int level)
{
	if (set->cmds[level]->executable == 0)
		handle_error("command not found\n", WRITE2);
	do_dup2(set->cmds[level]->io_fd);
	close(read_fd);
	execve(set->cmds[level]->cmd, set->cmds[level]->cmd_argv, set->envp);
	handle_error("execve failed", PERROR);
}

void	do_dup2(int io_fd[2])
{
	int	res;

	res = dup2(io_fd[0], STDIN_FILENO);
	if (res == -1)
		handle_error("dup2 error", PERROR);
	res = dup2(io_fd[1], STDOUT_FILENO);
	if (res == -1)
		handle_error("dup2 error", PERROR);
	close(io_fd[0]);
	close(io_fd[1]);
}
