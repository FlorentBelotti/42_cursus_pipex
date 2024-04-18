/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:31:01 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/18 20:03:58 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	get_and_exec_cmd(char *cmd, char **env)
{
	char	**clean_cmd;
	char	*path;

	clean_cmd = ft_split(cmd, ' ');
	if (!clean_cmd)
	{
		perror("ERROR : can't get the command\n");
		exit(EXIT_FAILURE);
	}
	path = found_path(cmd[0], env);
	if (!path)
	{
		perror("ERROR : can't get the path\n");
		exit(EXIT_FAILURE);
	}
}

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
