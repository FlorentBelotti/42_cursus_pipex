/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:31:01 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/22 10:11:40 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	pipe_fd[2];
	int	pid;

	if (ac != 5)
		return (perror("ERROR : invalid numbers of arguments\n"), 1);
	if (pipe(pipe_fd) == -1)
		return (perror("ERROR : using pipe\n"), 1);
	pid = fork();
	if (pid == -1)
		return (perror("ERROR : creating the fork\n"), 1);
	if (pid == 0)
		run_child_process(pipe_fd, av, env);
	else
		run_parent_process(pipe_fd, av, env);
}
