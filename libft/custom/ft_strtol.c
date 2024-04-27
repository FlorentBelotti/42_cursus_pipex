/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:09:14 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:57 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_strtol(const char *str)
{
	long	res;
	int		i;

	i = 2;
	res = 0;
	while (str[i])
	{
		res *= 16;
		if (ft_isdigit(str[i]))
			res += str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res += 10 + (str[i] - 'A');
		else if (str[i] >= 'a' && str[i] <= 'f')
			res += 10 + (str[i] - 'a');
		i++;
	}
	return (res);
}
