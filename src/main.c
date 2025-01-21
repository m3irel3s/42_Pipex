/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/21 11:49:35 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = init_struct();
	if (!envp[1])
		exit_program(pipex, "No envs found, open a new terminal\n", 2);
	if (argc == 5)
	{
		check_args_and_set(pipex, argv, envp);
		handle_child_processes(pipex, envp);
		exit_program(pipex, "", 1);
	}
	else
		exit_program(pipex, "Not valid input! Try ./pipex file1 \"cmd1\" \"cmd2\" \
file2\n", 2);
	return (0);
}
