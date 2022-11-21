/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:32:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/21 19:24:10 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_main_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	static t_arg_set	*info;

	if (argc <= 4)
		handle_error("piepx: few arguments", WRITE2);
	if (!ft_memcmp(argv[1], "here_doc", ft_max(ft_strlen(argv[1]), 8)))
		info = create_arg_set_for_heredoc(argc, argv, envp);
	else
		info = create_arg_set(argc, argv, envp);
	execute_cmd(info, 0);
	return (WEXITSTATUS(info->stat));
}
