/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:45:39 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/03 13:51:19 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	exit_program(t_file *file, char *str, int fd)
{
	if (file)
		free_struct(file);
	ft_putstr_fd(str, fd);
	exit(1);
}