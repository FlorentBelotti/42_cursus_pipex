/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:27:26 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 13:08:54 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	count_numbers(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb_size;
	long	nb;

	nb = (long)n;
	nb_size = count_numbers(nb);
	str = (char *)malloc(sizeof(char) * (nb_size + 1));
	if (!str)
		return (NULL);
	str[nb_size] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		nb = -nb;
	while (nb_size > 0)
	{
		str[--nb_size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
