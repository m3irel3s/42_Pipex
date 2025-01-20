/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/20 17:26:46 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = init_struct();
	if (!envp[1])
		return (1);
	if (argc == 5)
	{
		check_args_and_set(pipex, argv, envp);
		handle_child_processes(pipex, envp);
		exit_program(pipex, "", 1);
	}
	else
		exit_program(pipex, "Please provide only 4 arguments\n", 2);
	return (0);
}
