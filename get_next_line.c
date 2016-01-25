/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 16:16:57 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/23 16:18:12 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_read(t_list **gnl, t_list *tmp, int fd, int res)
{
	char			*buf;
	t_list			*list;

	buf = ft_strnew(BUFF_SIZE);
	list = NULL;
	while ((res = read(fd, buf, BUFF_SIZE)) > 0)
		ft_lstpush(&list, buf, res);
	ft_strdel(&buf);
	if (res == -1)
		return (-1);
	buf = ft_Strnew(ft_lstcontentsize(list) + 2);
	*buf = '\2';
	buf++;
	ft_lsttochar(list, buf);
	buf--;
	ft_lstpush(gnl, buf, ft_lstcontentsize(list) + 2);
	while (tmp->next)
		tmp = tmp->next;
	tmp->content_size = fd;
	ft_lstclear(&list);
	ft_strdel(&buf);
	return (1);
}

static int			ft_line(t_list **gnl, t_list *tmp, char **line, int fd)
{
	int				i;

	i = 0;
	while (tmp->content_size != fd)
		tmp = tmp->next;
	while (((char*)tmp->content)[i])
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*gnl = NULL;
	t_list			*tmp;

	tmp = *str;
	if (line == NULL)
		return (-1);
	if (gnl == NULL)
		if (ft_read(&gnl, tmp, fd, 0) < 0)
			return (-1);
	ft_line(&str, tmp, line, fd);
}
