/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2gnl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:55:27 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/28 18:05:17 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_gnl(int const fd, char **line)
{
	static t_list		*list = NULL;
	t_list				*begin;
	char				*buf;
	char				*tmp;
	char				**tab;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	begin = NULL;
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		ft_lstpush(&begin, buf, BUFF_SIZE);
		ft_bzero(buf, BUFF_SIZE);
	}


	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE * ft_lstsize(begin));
	tmp = ft_lsttochar(begin, tmp);
	// ft_putstr(tmp);
	free(tmp);


	tab = ft_strsplit(tmp, '\n');
	// for (int i = 0; tab[i]; i++)
	// {
	// 	ft_putendl(tab[i]);
	// }


	list = ft_lstnew("COUCOU", 6);
	*line = NULL;
	free(buf);
	free(begin);
	return (1);
}