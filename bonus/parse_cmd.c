/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:28:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 23:35:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmd.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	open_io_files(int file[2], char *input, char *output)
{
	file[0] = open(input, O_RDONLY);
	if (file[0] < 0)
		perror("failed opening input file");
	file[1] = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file[1] < 0)
		perror("failed opening output file");
}

t_arg_set	*create_arg_set(int argc, char **argv, char **envp)
{
	t_arg_set	*set;

	set = ft_malloc(FT_NULL, sizeof(t_arg_set));
	set->cmds = create_cmd_vector(argc - 3, &argv[2], envp);
	set->cmd_cnt = argc - 3;
	set->envp = envp;
	open_io_files(set->file, argv[1], argv[argc - 1]);
	return (set);
}

t_cmd_node	**create_cmd_vector(int cnt, char **input, char **envp)
{
	t_cmd_node	**cmds;
	char		**path;
	int			i;

	cmds = ft_calloc(cnt + 1, sizeof(t_cmd_node *));
	path = get_path_from_envp(envp);
	i = -1;
	while (++i < cnt)
	{
		cmds[i] = ft_calloc(1, sizeof(t_cmd_node));
		cmds[i]->executable = 1;
		cmds[i]->cmd_argv = ft_split(input[i], ' ');
		if (!cmds[i]->cmd_argv)
			handle_error("split failed", PERROR);
		if (!cmds[i]->cmd_argv[0])
		{
			cmds[i]->executable = 0;
			continue ;
		}
		cmds[i]->cmd = ft_strdup(cmds[i]->cmd_argv[0]);
		find_proper_path_of_cmd(cmds[i], path);
	}
	free_double_char_array(path);
	return (cmds);
}

char	**get_path_from_envp(char **envp)
{
	int		i;
	char	**paths;

	i = 0;
	while (envp[i] && ft_memcmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		handle_error("can't find PATH", WRITE2);
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

void	find_proper_path_of_cmd(t_cmd_node *node, char **path)
{
	char	*absolute_path;
	char	*cmd_name;
	int		i;

	if (!access(node->cmd, X_OK))
		return ;
	i = -1;
	while (path[++i])
	{
		absolute_path = ft_strjoin(path[i], "/");
		cmd_name = ft_strjoin(absolute_path, node->cmd_argv[0]);
		if (!access(cmd_name, X_OK))
			break ;
		free(cmd_name);
		free(absolute_path);
	}
	if (path[i] == 0)
	{
		node->executable = 0;
		return ;
	}
	free(node->cmd);
	free(absolute_path);
	node->cmd = cmd_name;
}
