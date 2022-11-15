/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:11:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:29:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_UTILS_BONUS_H
# define PIPEX_UTILS_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

enum e_print_option
{
	PERROR,
	WRITE2
};

size_t	ft_strlen(const char *s);

#endif