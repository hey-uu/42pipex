/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:34:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 21:16:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_CMD_H
# define PARSE_CMD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define NOFILEDIR "pipex: No such file or directory: "
# define NOCMD "pipex: command not found: "

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

// libft
void		*ft_malloc(char *error_message, size_t size_of);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strchr(const char *s, int c);

// utils
void		handle_error(char *message, int opt);
void		free_double_char_array(char **array);
void		printf_std_err(char *str1, char *str2, char *str3);

// parse_cmd functions
t_cmd_node	**create_cmd_vector(int cnt, char **in, char **envp);
char		**get_path_from_envp(char **envp);
char		*find_proper_path_of_cmd(t_cmd_node *node, char **path);

#endif