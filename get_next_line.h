/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:31:08 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/23 12:31:10 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include "libft/libft.h"
# include <fcntl.h>

t_list				*forc_list(t_list **head, const int fd);
int					create(const int fd, t_list *list);
int					pinl(t_list **list, char **line);
int					get_next_line(const int fd, char **line);
#endif
