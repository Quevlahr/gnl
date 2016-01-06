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

static void		ft_freestr(char **str)
{
	(*str)--;
	while (**str)
		(*str)--;
	ft_strdel(str);
}

static int		ft_strinit(int fd, char **str)
{
	char		*buf;
	int			i;
	t_list		*begin;
	int			last;

	buf = ft_strnew(BUFF_SIZE);
	begin = NULL;
	last = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		last = i;
		ft_lstpush(&begin, buf, i);
		ft_bzero(buf, i);
	}
	if (i == -1)
		return (-1);
	(*str) = ft_strnew(ft_lstcontentsize(begin) + 2);
	(*str)[0] = '\0';
	(*str)++;
	ft_lsttochar(begin, (*str));
	(*str)[ft_lstcontentsize(begin) + 1] = '\0';
	ft_lstclear(&begin);
	ft_strdel(&buf);
	return (last);
}

static int		ft_finish(char **str)
{
	if (**str == '\n')
	{
		(*str)++;
		if (**str == '\0')
		{
			ft_freestr(str);
			return (1);
		}
	}
	else if (**str == '\0')
	{
		ft_freestr(str);
		return (0);
	}
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				i;

	i = 0;
	if (line == NULL)
		return (-1);
	if (str == NULL)
		if (ft_strinit(fd, &str) < 0)
			return (-1);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = ft_strnew(i);
	i = 0;
	while (*str != '\0' && *str != '\n')
	{
		(*line)[i] = *str;
		str++;
		i++;
	}
	(*line)[i] = '\0';
	return (ft_finish(&str));
}
