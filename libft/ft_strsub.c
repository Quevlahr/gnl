/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:18:15 by quroulon          #+#    #+#             */
/*   Updated: 2015/12/01 16:47:53 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	test;
	int		i;

	i = 0;
	if (s == NULL || len > ft_strlen(s) || start > ft_strlen(s))
		return (NULL);
	str = ft_strnew(len + 1);
	while ((unsigned long)start < len)
	{
		test = ((char*)s)[start];
		str[i] = test;
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
