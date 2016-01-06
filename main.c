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

// int			main(void)
// {
// 	int				fd;
// 	char			*line;
// 	int				p[2];
// 	int				save_fd;

// 	fd = 1;
// 	save_fd = dup(fd);
// 	pipe(p);

// 	dup2(p[1], fd);
// 	write(fd, "aaa", 3);
// 	close(p[1]);
// 	dup2(save_fd, fd);
// 	get_next_line(p[0], &line);
// 	ft_putstr(line);
// 	free(line);
// 	return (0);
// }

// int			main(int ac, char **av)
// {
// 	int				fd;
// 	char			*line;

// 	fd = open(av[1], O_RDONLY);
// 	line = NULL;
// 	if (ac == 2 && fd != -1)
// 	{
// 		while (get_next_line(fd, &line) > 0)
// 		{
// 			ft_putstr(line);
// 		}
// 	}
// 	close(fd);
// 	free(line);
// 	return (0);
// }

int			main(int ac, char **av)
{
	int				fd;
	char			*line;

	fd = open(av[1], O_RDONLY);
	// fd = 2;
	line = NULL;
	if (ac == 2 && fd != -1)
		ft_putnbrdl(get_next_line(fd, &line));
	else
		ft_putendl("error");
	ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	ft_putnbrdl(get_next_line(fd, &line));
	// ft_putstr(line);
	get_next_line(fd, &line);
	// ft_putstr(line);
	get_next_line(fd, &line);
	// ft_putstr(line);
	get_next_line(fd, &line);
	// ft_putstr(line);
	close(fd);
	free(line);
	return (0);
}


	// fd = 1;
	// out = dup(fd); // créé une copie du fd fd dans out avec le plus pti nombre pas use
	// pipe(p); // Génère un tube, 0 lecture, 1 écriture. 1 est gardé en mémoire tant qu'il n'est pas lu

	// dup2(p[1], fd); // Créé une copie du fd p[1] dans le fd fd
	// write(fd, "aaa", 3); // Met aaa dans le fd p[1].
	// close(p[1]); // ferme p[1]
	// dup2(out, fd); // recré fd avec out (qui est la position de départ de fd)
	// gnl_ret = get_next_line(p[0], &line); // Lit le fd p[0] qui contient aaa
	// mt_assert(strcmp(line, "aaa") == 0);
	// mt_assert(gnl_ret == 0 || gnl_ret == 1);