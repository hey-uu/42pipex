/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:34:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 23:09:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMD_H
# define PARSE_CMD_H

# include "libft.h"
# include <stdlib.h>

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

char		**get_path_from_envp(char *envp[]);
t_cmd_node	**create_cmd_vector(int cnt, char **input, char **envp);
void		find_proper_path_of_cmd(t_cmd_node *node, char **path);
void		free_double_char_array(char **array);
void		handle_error(char *message, int opt);

#endif