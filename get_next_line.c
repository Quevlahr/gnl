/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:17:09 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/05 15:17:11 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_read(int const fd, char **str, char **line, int res)
{
	char			*buf;
	int				i;

	buf = ft_strnew(BUFF_SIZE);
	while ((res = (read(fd, buf, BUFF_SIZE) > 0)))
	{
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
		{
			*line = (*line == NULL) ? ft_strsub(buf, 0, i) : ft_strjoin(*line, ft_strsub(buf, 0, i));
			*str = ft_strsub(buf, ++i, ft_strlen(buf));
			if ((*str)[0] == '\0')
				ft_strdel(str);
			return (1);
		}
		else
		{
			if (*line == NULL)
				*line = ft_strnew(0);
			*line = ft_strjoin(*line, buf);
		}
	}
	if (fd == -1)
		ft_putendl("COUCOU");
	if (fd == -1 && res == -1)
		ft_putendl("WESH TAMAMA");
	if (res == -1)
		return (-1);
	if (res == 0 && *line == NULL && *str == NULL)
		return (0);
	if (res == 0 && *line == NULL)
	{
		*line = ft_strnew(0);
		*line = ft_strjoin(*line, *str);
		ft_strdel(str);
		return (1);
	}
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	int				i;
	static char		*str = NULL;

	i = 0;
	*line = NULL;
	if (line == NULL)
		return (-1);
	if (str != NULL)
	{
		*line = ft_strnew(0);
		while (str[i])
		{
			if (str[i] == '\n')
			{
				*line = ft_strjoin(*line, ft_strsub(str, 0, i));
				if (str[++i] != '\0')
					str = ft_strsub(str, i, ft_strlen(str));
				else
					ft_strdel(&str);
				return (1);
			}
			i++;
		}
		*line = ft_strjoin(*line, str);
		ft_strdel(&str);
	}
	return (ft_read(fd, &str, line, 0));
}
