/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:17:23 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/22 14:52:22 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* LIBFT INCLUDE */

# include "./libft/libft.h"

/* handle_path.c */

void	get_and_exec_cmd(char *cmd, char **env);
char	*extract_path_from_env(char **env);
char	*found_path(char *cmd, char **env);

/* handle_process.c */

void	run_child_process(int *pipe_fd, char **av, char **env);
void	run_parent_process(int *pipe_fd, char **av, char **env);

#endif
