/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:24:33 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/10 11:12:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

static void free_struct(t_pipex *pipex);

int	exit_program(t_pipex *pipex, char *str, int fd)
{
	free_struct(pipex);
	ft_putstr_fd(str, fd);
	exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static void free_struct(t_pipex *pipex)
{
	if(pipex)
	{
		free(pipex->path_1);
		free(pipex->path_2);
		// free(pipex->cmd_1);
		// free(pipex->cmd_2);
		close(pipex->fd_1);
		close(pipex->fd_2);
	}
	free(pipex);
}
