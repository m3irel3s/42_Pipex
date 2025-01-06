/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:53:59 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/06 15:21:49 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

t_file	*init_struct(void)
{
	t_file *file;

	file = malloc(sizeof(t_file));
	return (file);
}