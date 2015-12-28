/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:43:48 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/18 20:40:55 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000

# include "libft.h"
# include <string.h> // pour size_t
# include <stdlib.h> // pour malloc
# include <unistd.h> // pour read
# include <stdio.h> // pour EOF

int			get_next_line(int const fd, char **line);

#endif
