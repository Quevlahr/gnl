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

static int			ft_read(t_list **str, int fd, t_list *tmp)
{
	int				i;
	char			*buf;
	t_list			*list;
	t_list			*list_tmp;

	i = 0;
	buf = ft_strnew(BUFF_SIZE);
	list_tmp = NULL;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
		ft_lstpush(&list, buf, i);
	ft_strdel(&buf);
	if (i == -1)
		return (-1);
	list_tmp->content = (char*)malloc(sizeof(char) * ft_lstcontentsize(list) + 2);
	((char*)list_tmp->content)[0] = '\2';
	list_tmp->content++;
	list_tmp->content = ft_lsttochar(list, buf);
	list_tmp->content_size = fd;
	if (tmp == NULL)
		*str = list_tmp;
	else
		tmp->next = list_tmp;
	ft_lstclear(&list);
	// list = NULL;
	// list->content



	// ft_lstpush(str, buf, ft_lstcontentsize(list) + 1);
	// if (tmp != NULL)
	// 	tmp = tmp->next;
	// tmp->content_size = (tmp->content_size * 1000) + fd;
	// ft_strdel(&buf);
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*str = NULL;
	t_list			*tmp;

	tmp = str;
	if (line == NULL)
		return (-1);
	if (str == NULL)
	{
		if (ft_read(&str, fd, tmp) < 0)
			return (-1);
	}
	else
	{	
		while (tmp->next && tmp->content_size != (size_t)fd)
			tmp = tmp->next;
		if (tmp->content_size != (size_t)fd)
			if (ft_read(&str, fd, tmp) < 0)
				return (-1);
	}
	return (1);
}
