/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_handle_here_doc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:21:22 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/26 17:24:57 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc_child_process(int *pipe_fd, char **av)
{
	char	*line;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		ft_putstr(line);
		free(line);
	}
}

void	here_doc_parent_process(int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	wait(NULL);
}

void	handle_here_doc(char **av)
{
	int	pipe_fd[2];
	int	pid;

	if (pipe(pipe_fd) == -1)
	{
		perror("ERROR : creating the pipe\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : creating the fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		here_doc_child_process(pipe_fd, av);
	else
		here_doc_parent_process(pipe_fd);
}
