/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:32:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 15:30:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_main.h"

int	main(int argc, char *argv[], char *envp[])
{
	static t_arg_set	*info;

	if (argc <= 4)
		handle_error("few arguments", WRITE2);
	info = create_arg_set(argc, argv, envp);
	execute_cmd(info, 0);
	exit(0);
}
