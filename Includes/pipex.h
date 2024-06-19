/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:17:23 by fbelotti          #+#    #+#             */
/*   Updated: 2024/06/20 00:23:48 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* LIBFT INCLUDE */

# include "./libft/Includes/libft.h"

/* INCLUDE */

# include <sys/wait.h>

	/* MANDATORY_PART */

/* handle_path.c */

void	get_and_exec_cmd(char *cmd, char **env);
char	*extract_path_from_env(char **env);
char	*found_path(char *cmd, char **env);

/* handle_process.c */

void	run_child_process(int *pipe_fd, char **av, char **env);
void	run_parent_process(int *pipe_fd, char **av, char **env);

	/* BONUS_PART */

void	here_doc_child_process(int *pipe_fd, char **av);
void	here_doc_parent_process(int *pipe_fd);
void	handle_here_doc(char **av);
void	bonus_get_and_exec_cmd(char *cmd, char **env);
char	*bonus_extract_path_from_env(char **env);
char	*bonus_found_path(char *cmd, char **env);
void	run_child_process_b(int *pipe_fd, char *cmd, char **env);
void	run_parent_process_b(int *pipe_fd, char *cmd, char **env);
void	manage_files(int input_file, int output_file);
void	create_pipes(char *cmd, char **env);
int		open_here_doc_output(int ac, char **av);

#endif
