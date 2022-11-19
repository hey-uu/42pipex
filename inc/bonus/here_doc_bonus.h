/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:27:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/19 13:06:41 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_BONUS_H
# define HERE_DOC_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cmd_node
{
	char	*cmd;
	char	**cmd_arg;
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
void		*ft_malloc(char *error_message, size_t size_of);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_max(int a, int b);
size_t		ft_strlen(const char *s);

// heredoc functions
void		open_io_files_for_heredoc(int *file, char *limiter, char *output);
char		*get_random_temp_file(void);
void		get_heredoc_input(int fd, char *limiter);

// parse cmd functions
t_cmd_node	**create_cmd_vector(int cnt, char **input, char **envp);

#endif