/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:12:04 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/17 16:03:50 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	search_for_newline(t_gnl *list)
{
	int		i;
	t_gnl	*last;

	if (list == NULL)
		return (0);
	last = gnl_lstlast(list);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_gnl	*gnl_lstlast(t_gnl *list)
{
	t_gnl	*current;

	current = list;
	if (current == NULL)
		return (current);
	while (current->next)
		current = current->next;
	return (current);
}

void	free_list(t_gnl *list)
{
	t_gnl	*current;
	t_gnl	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

void	malloc_of_line(char **line, t_gnl *list)
{
	int		newline_index;
	int		i;

	newline_index = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\n' && list->content[i])
		{
			i++;
			newline_index++;
		}
		if (list->content[i] == '\n')
			newline_index++;
		list = list->next;
	}
	*line = malloc(sizeof(char) * (newline_index + 1));
}
