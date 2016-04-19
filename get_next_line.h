/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:17:34 by quroulon          #+#    #+#             */
/*   Updated: 2016/04/05 15:18:13 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int					get_next_line(int const fd, char **line);

#endif
