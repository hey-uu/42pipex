/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:12:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 21:16:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_MAIN_BONUS_H
# define PIPEX_MAIN_BONUS_H

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
	t_cmd_node	**cmds;
	int			cmd_cnt;
	char		**envp;
	char		*in;
	char		*out;
	int			is_heredoc;
	int			io_fd[2];
	int			stat;
}	t_arg_set;
enum e_print_option
{
	PERROR,
	WRITE2
};

//libft
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_max(int a, int b);
size_t		ft_strlen(const char *s);

// pipex main
t_arg_set	*create_arg_set(int cnt, char **in, char **envp);
t_arg_set	*create_arg_set_for_heredoc(int argc, char **argv, char **envp);
void		show_cmd_vector(t_cmd_node **cmds);
int			execute_cmd(t_arg_set *set, int lev);
void		handle_error(char *message, int opt);

#endif