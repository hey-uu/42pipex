/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:12:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 00:29:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_MAIN_H
# define PIPEX_MAIN_H

# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

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

t_arg_set	*create_arg_set(int cnt, char **input, char **envp);
t_arg_set	*create_arg_set_for_here_doc(int argc, char **argv, char **envp);
void		show_cmd_vector(t_cmd_node **cmds);
void		execute_cmd(t_arg_set *set, int level);
void		handle_error(char *message, int opt);

#endif