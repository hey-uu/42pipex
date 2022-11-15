/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:09:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 23:14:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_cmd.h"
#include <stdio.h>

void	free_double_char_array(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	handle_error(char *message, int opt)
{
	if (opt == PERROR)
		perror(message);
	else
		write(2, message, ft_strlen(message));
	exit(1);
}
