/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:14:06 by quroulon          #+#    #+#             */
/*   Updated: 2015/11/25 16:20:40 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	src2[len];
	size_t	i;

	i = 0;
	while (i < len)
	{
		src2[i] = ((char*)src)[i];
		i++;
	}
	dst = ft_memcpy(dst, src2, len);
	return (dst);
}
