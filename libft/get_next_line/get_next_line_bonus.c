/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:11:12 by fbelotti          #+#    #+#             */
/*   Updated: 2024/03/17 16:03:55 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	clean_list(t_gnl **list)
{
	t_gnl	*last;
	t_gnl	*next_node;
	int		i;
	int		j;

	next_node = malloc(sizeof(t_gnl));
	if (next_node == NULL || list == NULL)
		return ;
	next_node->next = NULL;
	last = gnl_lstlast(*list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	next_node->content = malloc(sizeof(char)
			* ((ft_strlen(last->content) - i) + 1));
	if (next_node->content == NULL)
		free(next_node);
	j = 0;
	while (last->content[i])
		next_node->content[j++] = last->content[i++];
	next_node->content[j] = '\0';
	free_list(*list);
	*list = next_node;
}

static void	add_to_list(t_gnl **list, char *buffer, int char_read)
{
	int		i;
	t_gnl	*last;
	t_gnl	*new_node;

	new_node = malloc(sizeof(t_gnl));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (char_read + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < char_read)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	last = gnl_lstlast(*list);
	last->next = new_node;
}

void	create_list(t_gnl **list, int fd)
{
	char	*buffer;
	int		char_read;

	char_read = 1;
	while (!search_for_newline(*list) && char_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		char_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && char_read == 0) || char_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		add_to_list(list, buffer, char_read);
		free(buffer);
	}
}

void	put_line(t_gnl *list, char **line)
{
	int	j;
	int	i;

	if (!list)
		return ;
	malloc_of_line(line, list);
	if (!line)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break ;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

char	*get_next_line(int fd)
{
	static t_gnl	*list[4096];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(list[fd]), list[fd] = NULL, NULL);
	line = NULL;
	create_list(&list[fd], fd);
	if (list[fd] == NULL)
		return (NULL);
	put_line(list[fd], &line);
	clean_list(&list[fd]);
	if (line[0] == '\0')
	{
		free_list(list[fd]);
		list[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
