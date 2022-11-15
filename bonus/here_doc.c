/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:23:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 09:36:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmd.h"
#include "libft.h"
#include "get_next_line.h"
#include "here_doc.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

t_arg_set	*create_arg_set_for_here_doc(int argc, char **argv, char **envp)
{
	t_arg_set	*set;

	set = ft_malloc(FT_NULL, sizeof(t_arg_set));
	set->cmds = create_cmd_vector(argc - 4, &argv[3], envp);
	set->cmd_cnt = argc - 4;
	set->envp = envp;
	open_io_files_for_here_doc(set->file, argv[2], argv[argc - 1]);
	return (set);
}

void	open_io_files_for_here_doc(int file[2], char *limiter, char *output)
{
	file[0] = open("tmp/temp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	if (file[0] < 0)
		perror("failed opening input file");
	get_heredoc_input(file[0], limiter);
	close(file[0]);
	file[0] = open("tmp/temp", O_RDONLY);
	unlink("tmp/temp");
	file[1] = open(output, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file[1] < 0)
		perror("failed opening output file");
}

void	get_heredoc_input(int fd, char *limiter)
{
	char	*line;

	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		// write(1, line, ft_strlen(line));
		if (!ft_memcmp(line, limiter, \
			ft_max(ft_strlen(line) - 1, ft_strlen(limiter))))
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
}
