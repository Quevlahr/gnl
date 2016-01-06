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

# define BUFF_SIZE 32

# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int					get_next_line(int const fd, char **line);
int					ft_gnl(int const fd, char **line);

#endif
