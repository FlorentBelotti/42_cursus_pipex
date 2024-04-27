/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:01:47 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/27 16:19:40 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	get_and_exec_cmd(char *cmd, char **env)
{
	char	**clean_cmd;
	char	*path;

	clean_cmd = ft_split(cmd, ' ');
	if (!clean_cmd)
	{
		perror("ERROR : split failure\n");
		exit(EXIT_FAILURE);
	}
	path = found_path(clean_cmd[0], env);
	if (!path)
	{
		ft_free_array(clean_cmd);
		perror("ERROR : found_path failure\n");
		exit(EXIT_FAILURE);
	}
	if (execve(path, clean_cmd, env) == -1)
	{
		perror("ERROR : command cannot be executed\n");
		ft_free_array(clean_cmd);
		free(path);
		exit(EXIT_FAILURE);
	}
}

char	*extract_path_from_env(char **env)
{
	int		i;
	char	*prefix;

	prefix = "PATH=";
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], prefix, 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (perror("ERROR : can't found PATH in the environnement\n"), NULL);
}

char	*found_path(char *cmd, char **env)
{
	char	*each_path;
	char	*exec_path;
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(extract_path_from_env(env), ':');
	if (!paths)
	{
		perror("ERROR : path extract failed\n");
		exit(EXIT_FAILURE);
	}
	while (paths[i])
	{
		each_path = ft_strjoin(paths[i], "/");
		exec_path = ft_strjoin(each_path, cmd);
		free(each_path);
		if (access(exec_path, X_OK) == 0)
			return (ft_free_array(paths), exec_path);
		free(exec_path);
		i++;
	}
	ft_free_array(paths);
	return (NULL);
}
