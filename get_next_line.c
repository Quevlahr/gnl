/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:25:10 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/11 14:27:19 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_read(t_list **str, int fd, t_list *tmp, int i)
{
	char			*buf;
	t_list			*list;

	buf = ft_strnew(BUFF_SIZE);
	list = NULL;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
		ft_lstpush(&list, buf, i);
	ft_strdel(&buf);
	if (i == -1)
		return (-1);
	buf = NULL;
	buf = (char*)malloc(sizeof(char) * ft_lstcontentsize(list) + 2);
	ft_bzero(buf, ft_lstcontentsize(list) + 2);
	buf[0] = '\2';
	buf++;
	ft_lsttochar(list, buf);
	buf--;
	ft_lstpush(str, buf, ft_lstcontentsize(list) + 2);
	tmp = *str;
	while (tmp->next)
		tmp = tmp->next;
	tmp->content_size = fd;
	ft_lstclear(&list);
	ft_strdel(&buf);
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*str = NULL;
	t_list			*tmp;

	tmp = str;
	if (line == NULL)
		return (-1);
	while (tmp && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp == NULL)
		if (ft_read(&str, fd, tmp, 0) < 0)
			return (-1);
	ft_read();
	return (0);
}
