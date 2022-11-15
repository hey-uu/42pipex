/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:26:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/14 04:06:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*head = FT_NULL;
	t_gnl_list			*cur;
	char				*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || !find_node(&head, &cur, fd))
		return (FT_NULL);
	res = FT_NULL;
	while (1)
	{
		if (cur->offset == (size_t) cur->rbytes)
			if (!read_buffer_size(&head, cur, res))
				return (FT_NULL);
		if (cur->rbytes == 0)
			if (!process_error(&head, cur, FT_NULL))
				return (res);
		if (cur->buff[cur->offset] == '\n')
			return (append_line(&head, cur, &res, 1));
		if (cur->offset == (size_t) cur->rbytes - 1)
			if (!append_line(&head, cur, &res, 0))
				return (FT_NULL);
		cur->offset++;
		cur->len++;
	}
}
