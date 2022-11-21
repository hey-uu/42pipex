/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_execute_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 21:19:10 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_AND_EXECUTE_BONUS_H
# define FORK_AND_EXECUTE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>

# define NOFILEDIR "pipex: No such file or directory: "
# define NOCMD "pipex: command not found: "
# define NOPERMIT "pipex: permission denied: "

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

// libft
char	*ft_strchr(const char *s, int c);

// fork_and_execute functions
void	determine_io_fd(t_arg_set *set, int fd[2], int lev);
void	run_child_process(t_arg_set *set, int read_fd, int lev);
void	do_dup2(int io_fd[2]);

// utils
void	handle_error(char *message, int opt);
void	printf_std_err(char *str1, char *str2, char *str3);

#endif