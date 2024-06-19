/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:02:23 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/20 00:24:15 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	run_child_process(int *pipe_fd, char **av, char **env)
{
	int	fd_1;

	close(pipe_fd[0]);
	fd_1 = open(av[1], O_RDONLY, 0777);
	if (fd_1 == -1)
		return (perror("ERROR : while opening file_1\n"));
	dup2(fd_1, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	get_and_exec_cmd(av[2], env);
	close(fd_1);
}

void	run_parent_process(int *pipe_fd, char **av, char **env)
{
	int	fd_2;

	close(pipe_fd[1]);
	fd_2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_2 == -1)
	{
		perror("ERROR : while opening file_2\n");
		exit(EXIT_FAILURE);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd_2, STDOUT_FILENO);
	close(pipe_fd[0]);
	get_and_exec_cmd(av[3], env);
	close(fd_2);
	wait(NULL);
}
