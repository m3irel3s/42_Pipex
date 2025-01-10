/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:57:42 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/10 11:22:53 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "42_Libft/FT_Libft/inc/libft.h"
# include "42_Libft/FT_Printf/inc/ft_printf.h"
# include "42_Libft/Get_next_line/inc/get_next_line.h"
# include <sys/types.h>

//===============================================================//
//                          STRUCTURES                           //
//===============================================================//

typedef struct s_pipex
{
	char	*path_1;
	char	*path_2;
	char	*cmd_1;
	char	*cmd_2;
	int		fd_1;
	int		fd_2;
}	t_pipex;

//===============================================================//
//                             INITS                             //
//===============================================================//

t_pipex	*init_struct(void);

//===============================================================//
//                             PARSE                             //
//===============================================================//

char	*add_cmd_to_path(char **arr, char *cmd);
char	*get_path(t_pipex *pipex, char **env, char *cmd);
void	check_args_and_set(t_pipex *pipex, char **argv, char **envp);

//===============================================================//
//                             UTILS                             //
//===============================================================//

void	handle_child_processes(t_pipex *pipex, char **envp, char **argv);
void	handle_first_child(t_pipex *pipex, char **envp, char **argv, int *pipe_fds);
void	handle_second_child(t_pipex *pipex, char **envp, char **argv, int *pipe_fds);
void	free_arr(char **arr);
int		exit_program(t_pipex *pipex, char *str, int fd);


#endif