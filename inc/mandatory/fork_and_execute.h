/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:10:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_AND_EXECUTE_H
# define FORK_AND_EXECUTE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_cmd_node
{
	char	*cmd;
	char	**cmd_argv;
	int		executable;
	int		io_fd[2];
}	t_cmd_node;

typedef struct s_arg_set
{
	t_cmd_node	**cmds;
	int			cmd_cnt;
	char		**envp;
	int			file[2];
}	t_arg_set;

enum e_print_option
{
	PERROR,
	WRITE2
};

// libft

// fork_and_execute functions
void	determine_io_fd(t_arg_set *set, int fd[2], int level);
void	run_child_process(t_arg_set *set, int read_fd, int level);
void	do_dup2(int io_fd[2]);

// utils
void	handle_error(char *message, int opt);

#endif