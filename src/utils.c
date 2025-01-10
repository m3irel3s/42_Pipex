/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:14:59 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/10 11:55:54 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	handle_child_processes(t_pipex *pipex, char **envp, char **argv)
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_program(pipex, "Error creating communication channel\n", 2);
	pid_1 = fork();
	if (pid_1 == -1)
		exit_program(pipex, "Error forking 1st child\n", 2);
	if (pid_1 == 0)
		handle_first_child(pipex, envp, argv, fd);
	pid_2 = fork();
	if (pid_2 == -1)
		exit_program(pipex, "Error forking 2nd child\n", 2);
	if (pid_2 == 0)
		handle_second_child(pipex, envp, argv, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);
}

void	handle_first_child(t_pipex *pipex, char **envp, char **argv, int *fd)
{
	dup2(pipex->fd_1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	char **cmd_arr = ft_split(argv[2], ' ');
	execve(pipex->path_1, cmd_arr, envp);
}

void	handle_second_child(t_pipex *pipex, char **envp, char **argv, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(pipex->fd_2, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	char **cmd_arr = ft_split(argv[3], ' ');
	execve(pipex->path_2, cmd_arr, envp);
}