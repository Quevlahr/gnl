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

// static void		ft_freestr(char *str)
// {
// 	str--;
// 	while (*str)
// 		str--;
// 	free(str);
// 	str = NULL;
// }

int				ft_lstcontentsize(t_list *begin)
{
	t_list		*list;
	int			i;

	list = begin;
	i = 0;
	while (list)
	{
		i += ft_strlen(list->content);
		list = list->next;
	}
	return (i);
}

static int		ft_strinit(int fd, char **str)
{
	char		*buf;
	int			i;
	t_list		*begin;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	i = 15;
	begin = NULL;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putstr(buf);
		ft_lstpush(&begin, buf, BUFF_SIZE);
		ft_bzero(buf, BUFF_SIZE);
	}
	(*str) = (char*)malloc(sizeof(char) * ft_lstcontentsize(begin) + 2);
	(*str)[0] = '\0';
	(*str)++;
	ft_lsttochar(begin, (*str));
	// ft_putnbrdl(ft_lstcontentsize(begin) + 1);
	// (*str)[ft_lstcontentsize(begin) + 1] = '\0';
	// ft_putstr((*str));
	free(begin);
	free(buf);
	return (i);
}

// static int		ft_findln(char *str)
// {
// 	int			i;
// 	int			nb_ln;

// 	i = 0;
// 	nb_ln = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\n')
// 			nb_ln++;
// 		else if (str[i] != '\n' || str[i] != '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (nb_ln);
// }

int				get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				i;

	i = 0;
	*line = NULL;
	if (str == NULL)
		if (ft_strinit(fd, &str) < 0)
			return (-1);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	*line = (char*)malloc(sizeof(char) * i);
	i = 0;
	while (*str != '\0' && *str != '\n')
	{
		(*line)[i] = *str;
		str++;
		i++;
	}
	(*line)[i] = '\0';
	if (*str != '\0')
		str++;
	if (*str == '\0' && ft_strcmp(*line, str) == 0)
		return (0);
	// else if (str[0] == '\0' && str[1] == '0')
	// {
	// 	return (0);
	// }
	// else if (str[0] == '\0')
	// 	str[1] = '0';
	// else if (*str == '\0' && --(*str) == '\n')
	// 	return (0);
	// if (*str == '\0' && j > 0)
	// 	ft_freestr(str);
	return (1);
}
