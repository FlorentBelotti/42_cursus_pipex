/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:05:26 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 13:09:18 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dest;
	i = 0;
	if (s1 == s2)
		return (dest);
	if (s2 < s1)
	{
		while (n--)
			*s2++ = *s1++;
	}
	else
	{
		i = n;
		while (i > 0)
		{
			s2[i - 1] = s1[i - 1];
			i--;
		}
	}
	return (dest);
}
