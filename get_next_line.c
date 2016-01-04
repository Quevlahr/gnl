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
// 	if (*str == '\0')
// 	{
// 		ft_putendl("ZEXTRCYTVUBI");
// 		str--;
// 		while (*str)
// 			str--;
// 		free(str);
// 		str = NULL;
// 	}
// }

static char		*ft_strinit(int fd, char *str)
{
	char		*buf;
	int			i;
	t_list		*begin;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	i = 0;
	begin = NULL;
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		ft_lstpush(&begin, buf, BUFF_SIZE);
		ft_bzero(buf, BUFF_SIZE);
	}
	str = (char*)malloc(sizeof(char) * BUFF_SIZE * ft_lstsize(begin) + 1);
	str[0] = '\0';
	str++;
	ft_lsttochar(begin, str);
	free(begin);
	free(buf);
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	static char		*str = NULL;
	int				i;

	i = 0;
	if (str == NULL)
		str = ft_strinit(fd, str);
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
	// ft_freestr(str);
	return (1);
}
