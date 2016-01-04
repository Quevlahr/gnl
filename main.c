/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:20:08 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/22 15:20:23 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h> // pour open

/*
** go='gccw -I libft/includes -c get_next_line.c main.c; gcc -o gnt get_next_line.o main.o -L libft -lft;'
*/

int			main(int ac, char **av)
{
	int				fd;
	char			*line;

	fd = open(av[1], O_RDONLY);
	line = NULL;
	if (ac == 2 && fd != -1)
	{
		// get_next_line(fd, &line);
		while (get_next_line(fd, &line) > 0)
		{
			// ft_putstr(line);
		}
	}
	// else
	// 	ft_putendl("error");
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	// get_next_line(fd, &line);
	// ft_putstr(line);
	close(fd);
	free(line);
	return (0);
}
