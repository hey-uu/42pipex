/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 05:30:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 23:09:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parse_cmd.h"

void	show_cmd_vector(t_cmd_node **cmds)
{
	int	i;
	int	j;

	if (!cmds)
	{
		perror("this is NULL");
		exit(1);
	}
	i = -1;
	while (cmds[++i])
	{
		printf("-------------------------------\n");
		printf("  %dth node\n", i);
		printf("  path of cmd : %s\n", cmds[i]->cmd);
		printf("  arguments of cmd :\n  ");
		j = -1;
		while (cmds[i]->cmd_argv[++j])
			printf("|%s| ", cmds[i]->cmd_argv[j]);
		printf("\n");
	}
	printf("-------------------------------\n");
}
