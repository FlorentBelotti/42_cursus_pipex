/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:06:38 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 13:10:41 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;

	i = 0;
	j = 0;
	s2_len = ft_strlen(s2);
	if (s2[0] == '\0')
	{
		return ((char *)s1);
	}
	while (s1[i] && i < len)
	{
		while (s1[i + j] == s2[j] && s2[j] && (i + j) < len)
		{
			j++;
		}
		if (j == s2_len)
		{
			return ((char *)&s1[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
