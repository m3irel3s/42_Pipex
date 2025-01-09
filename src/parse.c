/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:15:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:31 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	check_args_and_set(t_pipex *pipex, char **argv)
{
	pipex->fd_1 = open(argv[1], O_RDONLY);
	if (pipex->fd_1 == -1)
		exit_program(pipex, "Error opening fd_1\n", 2);
	pipex->fd_2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_2 == -1)
		exit_program(pipex, "Error opening fd_2\n", 2);
}
