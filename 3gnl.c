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
	if (begin != NULL)
	{
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
	}
	ft_strdel(&buf);
	return (i);
}

static int		ft_finish(char **str)
{
	if (**str == '\n')
	{
		(*str)++;
		if (**str == '\0')
		{
			(*str)--;
			while (**str)
				(*str)--;
			// ft_strdel(str);
			str = NULL;
			return (1);
		}
	}
	else if (**str == '\0')
	{
		(*str)--;
		while (**str)
			(*str)--;
		// ft_strdel(str);
		str = NULL;
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*str = NULL;
	t_list			*tmp;
	int				i;

	i = 0;
	tmp = str;
	if (line == NULL)
		return (-1);
	while (tmp != NULL && tmp->content_size != (size_t)fd)
		tmp = tmp->next;

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
	return (ft_finish((char**)(&(tmp->content))));
	// if (*((char*)tmp->content) == '\n')
	// 	tmp->content++;
	// tmp = str;
	// while (tmp)
	// {
	// 	ft_putendl(tmp->content);
	// 	ft_putstr("Voici le fd : ");
	// 	ft_putnbrdl(tmp->content_size);
	// 	tmp = tmp->next;
	// }
	return (1);
	// 	if (ft_strinit(fd, &str) < 0)
	// 		return (-1);
	// while (str[i] != '\0' && str[i] != '\n')
	// 	i++;
	// *line = ft_strnew(i);
	// i = 0;
	// while (*str != '\0' && *str != '\n')
	// {
	// 	(*line)[i] = *str;
	// 	str++;
	// 	i++;
	// }
	// (*line)[i] = '\0';
	// return (ft_finish(&str));
}
