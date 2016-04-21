/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 11:45:57 by quroulon          #+#    #+#             */
/*   Updated: 2016/01/06 11:46:04 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstclear(t_list **begin)
{
	t_list		*tmp;
	t_list		*list;

	list = *begin;
	while (list != NULL)
	{
		tmp = list;
		list = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	*begin = NULL;
}
