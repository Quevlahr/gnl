/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:46:14 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/06 11:46:16 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int				ft_lstcontentsize(t_list *begin)
{
	t_list		*list;
	int			i;

	list = begin;
	i = 0;
	while (list)
	{
		i += ft_strlen(list->content);
		list = list->next;
	}
	return (i);
}
