/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 18:15:08 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*new;
	size_t			total;
	size_t			i;

	if (count > 0 && size > FT_SIZE_MAX / count)
		ft_exit(FT_NULL, BADALLOC);
	total = count * size;
	new = ft_malloc(FT_NULL, total);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return ((void *) new);
}
