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

static int			ft_finish(t_list **str, t_list *tmp)
{
	tmp = *str;
	while (tmp && ((char*)tmp->content)[0] == '\0')
		tmp = tmp->next;
	if (tmp == NULL)
	{
		tmp = *str;
		while (tmp)
		{
			while (((char *)tmp->content)[0] != '\2')
				tmp->content--;
			tmp = tmp->next;
		}
		*str = NULL;
		return (1);
	}
	return (0);
}

static int 			ft_helper(t_list **str, t_list *tmp, int fd)
{
	tmp = *str;
	while (tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (*((char*)tmp->content) == '\n')
	{
		tmp->content++;
		if (*((char*)tmp->content) == '\0')
			ft_finish(str, NULL);
	}
	else if (*((char*)tmp->content) == '\0')
	{
		ft_finish(str, NULL);
		return (0);
	}
	return (1);
}

static int			ft_line(t_list **str, int fd, t_list *tp, char **line)
{
	int				i;

	i = 0;
	tp = *str;
	while (tp->content_size != (size_t)fd)
		tp = tp->next;
	if (*((char*)tp->content) == '\2')
		tp->content++;
	while (((char*)tp->content)[i] != '\0' && ((char*)tp->content)[i] != '\n')
		i++;
	*line = ft_strnew(i);
	i = 0;
	while (*((char*)tp->content) != '\0' && *((char*)tp->content) != '\n')
	{
		(*line)[i] = *((char*)tp->content);
		tp->content++;
		i++;
	}
	(*line)[i] = '\0';
	return (ft_helper(str, NULL, fd));
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
	return (ft_line(&str, fd, tmp, line));
}
