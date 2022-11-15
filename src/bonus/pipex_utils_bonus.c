/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:09:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 23:12:33 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils_bonus.h"

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
