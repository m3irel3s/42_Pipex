/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/03 14:54:04 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, char **argv)
{
	t_file	*file;

	file = init_struct();
	if (argc == 5)
	{
	}
	else
		exit_program(file, "Not enough arguments\n", 2);
}