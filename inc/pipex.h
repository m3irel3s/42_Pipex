/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:57:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/06 15:20:21 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "42_Libft/FT_Libft/inc/libft.h"
# include "42_Libft/FT_Printf/inc/ft_printf.h"
# include "42_Libft/Get_next_line/inc/get_next_line.h"

//===============================================================//
//                          STRUCTURES                           //
//===============================================================//

typedef struct s_file 
{
	char	*cmd_1;
	char	*cmd_2;
	int		fd_1;
	int		fd_2;
}	t_file;

//===============================================================//
//                             INITS                             //
//===============================================================//

t_file	*init_struct(void);

//===============================================================//
//                             UTILS                             //
//===============================================================//

void	free_struct(t_file *file);
void	exit_program(t_file *file, char *str, int fd);



#endif