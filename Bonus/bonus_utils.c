/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:39:25 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/26 17:04:20 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	manage_files(int input_file, int output_file)
{
	if (input_file == -1 || output_file == -1)
	{
		perror("ERROR : Can't open file\n");
		exit(EXIT_FAILURE);
	}
	dup2(input_file, STDIN_FILENO);
	close(input_file);
}

void	create_pipes(char *cmd, char **env)
{
	int	pid;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("ERROR : during pipe creation\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR : during process creation\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		run_child_process_b(pipe_fd, cmd, env);
	else
		run_parent_process_b(pipe_fd, cmd, env);
}

int	open_here_doc_output(int ac, char **av)
{
	int	output_file;

	if (ac < 6)
	{
		perror("ERROR : not enough args for here_doc");
		exit(EXIT_FAILURE);
	}
	output_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (output_file == -1)
	{
		perror("ERROR : can't open output_file for here_doc.\n");
		exit(EXIT_FAILURE);
	}
	return (output_file);
}
