/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:36:42 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/12 13:10:45 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	s_len;

	s_len = (ssize_t)ft_strlen(s);
	while (s_len >= 0)
	{
		if (s[s_len] == (char)c)
		{
			return ((char *)&s[s_len]);
		}
		s_len--;
	}
	return (NULL);
}
