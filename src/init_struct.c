/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:52:23 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/09 11:15:09 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

t_pipex	*init_struct(void)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->cmd_1 = NULL;
	pipex->cmd_2 = NULL;
	pipex->fd_1 = 0;
	pipex->fd_2 = 0;

	return (pipex);
}