/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:30:25 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/18 19:31:44 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_lstprint(t_list *begin)
{
	while (begin)
	{
		write(1, begin->content, begin->content_size);
		begin = begin->next;
	}
}
