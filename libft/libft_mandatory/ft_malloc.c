/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:47:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 18:02:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	*ft_malloc(char *error_message, size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
	{
		perror(error_message);
		exit(1);
	}
	return (new);
}
