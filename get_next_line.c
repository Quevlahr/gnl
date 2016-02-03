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
	buf = ft_strnew(ft_lstcontentsize(list) + 1);
	*buf = '\2';
	buf++;
	ft_lsttochar(list, buf);
	buf--;
	ft_lstpush(gnl, buf, ft_lstcontentsize(list) + 1);
	tmp = *gnl;
	while (tmp->next)
		tmp = tmp->next;
	tmp->content_size = fd;
	tmp->content++;
	ft_lstclear(&list);
	ft_strdel(&buf);
	return (1);
}

// static int			ft_freegnl(t_list **gnl, t_list *tmp)
// {
// 	int				i;

// 	i = 0;
// 	tmp = *gnl;
// 	while (tmp && ((char*)tmp->content)[0] == '\0')
// 		tmp = tmp->next;
// 	if (tmp == NULL)
// 	{
// 		tmp = *gnl;
// 		while (tmp && i)
// 		{
// 			while (((char *)tmp->content)[0] != '\2')
// 				tmp->content--;
// 			if (tmp->next == NULL)
// 				i = 0;
// 			tmp = tmp->next;
// 		}
// 		ft_lstclear(gnl);
// 		ft_lstclear(&tmp);
// 		*gnl = NULL;
// 		return (1);
// 	}
// 	return (0);
// }

static int		ft_freegnl(t_list **gnl, t_list *tmp)
{
	int		i;

	i = 1;
	tmp = *gnl;
	if (ft_lstsize(tmp) != 1)
		while (tmp)
		{
			if (((char *)tmp->content)[0] != '\0')
				return (1);
			tmp = tmp->next;
		}
	while (gnl && i == 1)
	{
		while (((char *)(*gnl)->content)[0] != '\2')
			(*gnl)->content--;
		if ((*gnl)->next == NULL)
			i = 0;
		*gnl = (*gnl)->next;
	}
	ft_lstclear(gnl);
	// ft_lstclear(&tmp);
	*gnl = NULL;
	return (1);
}

static int			ft_line(t_list **gnl, t_list *tmp, char **line, int fd)
{
	int				i;
	char			*str;

	i = 0;
	tmp = *gnl; //useless
	while (tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (((char*)tmp->content)[i] == '\0')
	{
		// while (((char *)tmp->content)[0] != '\2')
		// 	tmp->content--;
		// *gnl = NULL;
		// ft_finish(gnl, NULL);
		ft_freegnl(gnl, NULL);
		return (0);
	}
	while (((char*)tmp->content)[i] != '\0' && ((char*)tmp->content)[i] != '\n')
		i++;
	*line = ft_strnew(i + 1);
	str = ft_strnew(i + 1);
	i = 0;
	while (*((char*)tmp->content) != '\0' && *((char*)tmp->content) != '\n')
	{
		str[i] = *((char*)tmp->content);
		tmp->content++;
		i++;
	}
	ft_strcpy(*line, str);
	ft_strdel(&str);
	// (*line)[i] = '\0';
	if (*((char*)tmp->content) == '\n')
		tmp->content++;	
	if (*((char*)tmp->content) == '\0')
	{
		return (ft_freegnl(gnl, NULL));
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*gnl = NULL;
	t_list			*tmp;

	tmp = gnl;
	if (line == NULL)
		return (-1);
	// *line = NULL;
	while (tmp && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp == NULL)
		if (ft_read(&gnl, tmp, fd, 0) < 0)
			return (-1);
	tmp = gnl;
	return (ft_line(&gnl, tmp, line, fd));
}
