/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:23:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 09:36:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc_bonus.h"

t_arg_set	*create_arg_set_for_heredoc(int argc, char **argv, char **envp)
{
	t_arg_set	*set;

	set = ft_malloc(NULL, sizeof(t_arg_set));
	set->cmds = create_cmd_vector(argc - 4, &argv[3], envp);
	set->cmd_cnt = argc - 4;
	set->envp = envp;
	open_io_files_for_heredoc(set->file, argv[2], argv[argc - 1]);
	return (set);
}

void	open_io_files_for_heredoc(int file[2], char *limiter, char *output)
{
	char	*input;

	input = get_random_temp_file();
	file[0] = open(input, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file[0] < 0)
		perror("failed opening input file");
	get_heredoc_input(file[0], limiter);
	close(file[0]);
	file[0] = open(input, O_RDONLY);
	unlink(input);
	file[1] = open(output, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (file[1] < 0)
		perror("failed opening output file");
}

char	*get_random_temp_file(void)
{
	int		fd;
	char	*file_name;
	char	*new_file_name;
	char	buf[2];

	fd = open("/dev/urandom", O_RDONLY);
	file_name = ft_strdup("/tmp/pipex_tmp");
	buf[1] = 0;
	while (!access(file_name, F_OK))
	{
		read(fd, buf, 1);
		new_file_name = ft_strjoin(file_name, buf);
		free(file_name);
		file_name = new_file_name;
	}
	close(fd);
	return (file_name);
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
		if (!ft_memcmp(line, limiter, \
			ft_max(ft_strlen(line) - 1, ft_strlen(limiter))))
			break ;
		write(fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
}