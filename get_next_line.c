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

static int		ft_otherln(char *str)
{
	int			nb_ln;
	int			i;

	i = 0;
	nb_ln = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == EOF)
			return (i);
		i++;
	}
	return (nb_ln);
}

/*
** Chiant car ne fonctionne pas avec les gros buffer.
** Si le buffer est plus grand que la ligne d'apres.
*/

int				get_next_line(int const fd, char **line)
{
	char			*buf;
	t_list			*begin;
	int				i;
	int				j;
	int				other;
	static char		*test = NULL;

	buf = (char*)malloc(sizeof(char) * BUFF_SIZE);
	begin = NULL;
	i = 1;
	j = 0;
	while (i > 0 && read(fd, buf, BUFF_SIZE) > 0)
	{
		i = 1;
		while (i > 0 && i <= BUFF_SIZE)
		{
			if (buf[i - 1] == '\n' || buf[i - 1] == EOF)
				i *= -1;
			else
				i++;
		}
		ft_lstpush(&begin, buf, BUFF_SIZE);
		if (i > 0)
			ft_bzero(buf, BUFF_SIZE);
	}

	if (test != NULL && (other = ft_otherln(test)) > 0)
	{
		*line = (char*)malloc(sizeof(char) * other);
		ft_strncat(*line, test, other);
	}
	else
	{
		*line = (char*)malloc(sizeof(char) * ft_strlen(test) + 
			(BUFF_SIZE * ft_lstsize(begin)));
		ft_strncat(*line, test, ft_strlen(test));
		ft_lsttochar(begin, *line);
		(*line)[ft_strlen(test) + (BUFF_SIZE * (ft_lstsize(begin) - 1) + ft_abs(i + 1))] = '\0';


		free(test);
		i = ft_abs(i);
		test = (char*)malloc(sizeof(char) * (BUFF_SIZE - i));
		while (i < BUFF_SIZE)
		{
			test[j++] = buf[i++];
		}
		test[j] = '\0';
	}


	free(begin);
	free(buf);
	return (1);
}
