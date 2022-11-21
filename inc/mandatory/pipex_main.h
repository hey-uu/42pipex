/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:12:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 21:16:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_MAIN_H
# define PIPEX_MAIN_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_cmd_node
{
	char	*cmd;
	char	**args;
}	t_cmd_node;

typedef struct s_arg_set
{
	char		*in;
	char		*out;
	char		**envp;
	t_cmd_node	**cmds;
	int			cmd_cnt;
	int			io_fd[2];
	int			stat;
}	t_arg_set;

enum e_print_option
{
	PERROR,
	WRITE2
};

// parse_cmd
t_arg_set	*create_arg_set(int cnt, char **in, char **envp);
t_arg_set	*create_arg_set_for_here_doc(int argc, char **argv, char **envp);

// fork_and_execute
int			execute_cmd(t_arg_set *set, int lev);

// pipex_utils
void		handle_error(char *message, int opt);

#endif