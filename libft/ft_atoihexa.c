/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoihexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroulon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:18:54 by quroulon          #+#    #+#             */
/*   Updated: 2016/03/26 17:19:12 by quroulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_verif(char *str, int *i, int sign)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t' ||
			str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-')
		sign = -1;
	else if (str[*i] == '+')
		sign = 1;
	return (sign);
}

long				ft_atoihexa(char *str)
{
	int				i;
	long			res;
	int				sign;

	i = 0;
	res = 0;
	sign = ft_verif(str, &i, 1);
	while (ft_isdigit(str[i]) == 1 || (str[i] <= 'f' && str[i] >= 'a') ||
			(str[i] <= 'F' && str[i] >= 'A'))
	{
		if (str[i] == '\0')
			return (res);
		res *= 16;
		if (ft_isdigit(str[i]) == 1)
			res += (str[i] - '0') * 16;
		else if (str[i] <= 'f' && str[i] >= 'a')
			res += (str[i] - 'a' + 10) * 16;
		else if (str[i] <= 'F' && str[i] >= 'A')
			res += (str[i] - 'A' + 10) * 16;
		i++;
	}
	return (sign * (res /= 16));
}
