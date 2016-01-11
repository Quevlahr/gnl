/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:41:30 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/18 21:02:02 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//

static int		ft_strinit(int fd, t_list **str)
{
	char		*buf;
	int			i;
	t_list		*begin;
	t_list		*tmp;

	buf = ft_strnew(BUFF_SIZE);
	begin = NULL;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_lstpush(&begin, buf, i);
		ft_bzero(buf, i);
	}
	if (i == -1)
		return (-1);
	ft_strdel(&buf);
	buf = ft_strnew(ft_lstcontentsize(begin) + 2);
	buf[0] = '\0';
	buf++;
	ft_lsttochar(begin, buf);
	buf[ft_lstcontentsize(begin) + 1] = '\0';
	ft_lstpush(str, buf, ft_strlen(buf) + 1);
	tmp = *str;
	while (tmp->next != NULL && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	tmp->content_size = fd;
	ft_lstclear(&begin);
	buf--;
	ft_strdel(&buf);
	return (i);
}

void		ft_lstclr(t_list **begin_list)
{
	t_list	*free_list;
	t_list	*tmp;

	if (begin_list != NULL)
	{
		free_list = *begin_list;
		while (free_list)
		{
			tmp = free_list;
			free_list = free_list->next;
			free(tmp->content);
			free(tmp);
		}
		*begin_list = NULL;
	}
}

static int		ft_finish(t_list **str, int i, int rv, t_list *tmp)
{
	if (i == 1)
	{
		tmp = *str;
		if (ft_lstlen(tmp) != 1)
			while (tmp)
			{
				if (((char *)tmp->content)[0] != '\0')
					return (rv);
				tmp = tmp->next;
			}
		while (str && i == 1)
		{
			(*str)->content--;
			while (((char *)(*str)->content)[0] != '\2')
				(*str)->content--;
			if ((*str)->next == NULL)
				i = 0;
			*str = (*str)->next;
		}
		ft_lstclr(str);
		ft_lstclr(&tmp);
	}
	*str = NULL;
	return (rv);

	
	// if (**str == '\n')
	// {
	// 	(*str)++;
	// 	if (**str == '\0')
	// 	{
	// 		(*str)--;
	// 		while (**str)
	// 			(*str)--;
	// 		// ft_strdel(str);
	// 		str = NULL;
	// 		return (1);
	// 	}
	// }
	// else if (**str == '\0')
	// {
	// 	(*str)--;
	// 	while (**str)
	// 		(*str)--;
	// 	// ft_strdel(str);
	// 	str = NULL;
	// 	return (0);
	// }
	// return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*str = NULL;
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = str;
	if (line == NULL)
		return (ft_finish(&str, 0, -1, NULL));
	while (tmp != NULL && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp == NULL)
		if (ft_strinit(fd, &str) < 0)
			return (-1);


	tmp = str;
	while (tmp != NULL && tmp->content_size != (size_t)fd)
		tmp = tmp->next;

	if (tmp->content_size == (size_t)fd)
	{


		while (((char*)tmp->content)[i] != '\0' && ((char*)tmp->content)[i] != '\n')
			i++;
		*line = ft_strnew(i);
		i = 0;
		while (*((char*)tmp->content) != '\0' && *((char*)tmp->content) != '\n')
		{
			(*line)[i] = *((char*)tmp->content);
			tmp->content++;
			i++;
		}
		(*line)[i] = '\0';
	

	}
	if (((char *)tmp->content)[0] == '\0')
		return (ft_finish(&str, 0, 0, NULL));
	((char *)tmp->content)[0] == '\n' ? (tmp->content)++ : 0;
	if (((char *)tmp->content)[0] == '\0')
		return (ft_finish(&str, 1, 1, NULL));
	return (1);
	// return (ft_finish(&str));
}
