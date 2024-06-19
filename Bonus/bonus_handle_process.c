/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_handle_process.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:24:19 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/20 00:54:50 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	run_child_process_b(int *pipe_fd, char *cmd, char **env)
{
	(void)cmd;
	(void)env;
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	bonus_get_and_exec_cmd(cmd, env);
}

void	run_parent_process_b(int *pipe_fd, char *cmd, char **env)
{
	(void)cmd;
	(void)env;
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	wait(NULL);
}
