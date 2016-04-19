/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:19:12 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/05 15:19:13 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int				main(int ac, char **av)
{
	char			*line;
	int				fd;
	int				res = 0;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	if (ac == 2 && fd != -1)
	{
		// res = get_next_line(fd, &line);
		while ((res = get_next_line(fd, &line)) > 0)
		{
			ft_putendl(line);
			ft_putnbrdl(res);
		}
		ft_putnbrdl(res);
	}
	close(fd);
	free(line);
	return (0);
}
