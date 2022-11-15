/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:11:44 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 14:37:32 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

t_arg_set	*create_arg_set_for_here_doc(int argc, char **argv, char **envp);
void		open_io_files_for_here_doc(int *file, char *limiter, char *output);
void		get_heredoc_input(int fd, char *limiter);
char		*get_random_temp_file(void);

#endif