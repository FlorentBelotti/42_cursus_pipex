/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:24:29 by fbelotti          #+#    #+#             */
/*   Updated: 2024/04/26 17:24:14 by fbelotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **env)
{
	int	input_file;
	int	output_file;
	int	cmd_nb;

	if (ac < 5)
		return (perror("ERROR : not enough arguments\n"), 0);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		output_file = open_here_doc_output(ac, av);
		handle_here_doc(av);
		cmd_nb = 3;
	}
	else
	{
		input_file = open(av[1], O_RDONLY, 0644);
		output_file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		manage_files(input_file, output_file);
		cmd_nb = 2;
	}
	while (cmd_nb < ac - 2)
		create_pipes(av[cmd_nb++], env);
	dup2(output_file, STDOUT_FILENO);
	bonus_get_and_exec_cmd(av[ac - 2], env);
	close(output_file);
}
