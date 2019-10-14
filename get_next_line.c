/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 12:52:27 by gweasley          #+#    #+#             */
/*   Updated: 2019/09/30 12:52:46 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				create(const int fd, t_list *list)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	while (((char *)list->content)[i] != '\n')
	{
		if (((char *)list->content)[i] == '\0')
		{
			ret = read(fd, buff, BUFF_SIZE);
			if (!ret && ((char *)list->content)[0] == '\0')
				return (0);
			if (!ret)
				return (1);
			buff[ret] = '\0';
			if (!(tmp = ft_strjoin(list->content, buff)) || ret < 0)
				return (-1);
			free(list->content);
			list->content = tmp;
			i--;
		}
		i++;
	}
	return (1);
}

int				pin(t_list **list, char **line)
{
	long int	i;
	char		*tmp;

	i = 0;
	while (((char *)(*list)->content)[i] != '\n'
			&& ((char *)(*list)->content)[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(i + 1)))
		return (-1);
	ft_strncpy(*line, (*list)->content, i);
	(*line)[i] = '\0';
	if (ft_strlen((*list)->content) - i == 0)
	{
		free((*list)->content);
		(*list)->content = 0;
		return (1);
	}
	if (!(tmp = (char *)malloc(ft_strlen((*list)->content) - i)))
		return (-1);
	ft_strncpy(tmp, &((char *)(*list)->content)[i + 1],
			ft_strlen((*list)->content) - i);
	tmp[ft_strlen((*list)->content) - i] = '\0';
	free((*list)->content);
	(*list)->content = tmp;
	return (1);
}

t_list			*forc_list(t_list **head, const int fd)
{
	t_list *ptr;

	ptr = *head;
	if (!ptr)
	{
		if ((ptr = ft_lstnew("\0", 1)) == NULL)
			return (NULL);
		ptr->content_size = fd;
		*head = ptr;
		return (ptr);
	}
	while (ptr)
	{
		if (ptr->content_size == (size_t)fd)
			return (ptr);
		if (!(ptr->next))
			break ;
		ptr = ptr->next;
	}
	if ((ptr->next = ft_lstnew("\0", 1)) == NULL)
		return (NULL);
	ptr->next->content_size = fd;
	return (ptr->next);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*current_list;
	int				res;

	if (fd < 0 || !line || !(current_list = forc_list(&list, fd)))
		return (-1);
	if (!current_list->content)
		return (0);
	res = create(fd, current_list);
	if (res == 1)
		return (pin(&current_list, line));
	return (res);
}
