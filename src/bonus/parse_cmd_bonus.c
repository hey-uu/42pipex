/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:28:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 21:16:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_cmd_bonus.h"

t_arg_set	*create_arg_set(int argc, char **argv, char **envp)
{
	t_arg_set	*set;

	set = ft_malloc(NULL, sizeof(t_arg_set));
	set->in = argv[1];
	set->out = argv[argc - 1];
	set->envp = envp;
	set->cmds = create_cmd_vector(argc - 3, &argv[2], envp);
	set->cmd_cnt = argc - 3;
	set->stat = 0;
	set->is_heredoc = 0;
	return (set);
}

t_cmd_node	**create_cmd_vector(int cnt, char **in, char **envp)
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
		cmds[i]->args = ft_split(in[i], ' ');
		if (!cmds[i]->args)
			handle_error("pipex: split failed", PERROR);
		cmds[i]->cmd = find_proper_path_of_cmd(cmds[i], path);
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
		return (0);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		handle_error("pipex: split failed", PERROR);
	return (paths);
}

char	*find_proper_path_of_cmd(t_cmd_node *node, char **path)
{
	char	*absolute_path;
	char	*cmd_name;
	int		i;

	i = -1;
	if (!node->args[0])
		return (NULL);
	while (path && path[++i])
	{
		absolute_path = ft_strjoin(path[i], "/");
		cmd_name = ft_strjoin(absolute_path, node->args[0]);
		free(absolute_path);
		if (!access(cmd_name, X_OK))
			return (cmd_name);
		free(cmd_name);
	}
	if (ft_strchr(node->args[0], '/') && !access(node->args[0], X_OK))
		return (ft_strdup(node->args[0]));
	return (NULL);
}
