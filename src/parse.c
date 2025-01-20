/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:15:09 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/20 14:54:00 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	check_args_and_set(t_pipex *pipex, char **argv, char **envp)
{
	pipex->path_1 = get_path(pipex, envp, argv[2]);
	pipex->path_2 = get_path(pipex, envp, argv[3]);
	pipex->fd_1 = open(argv[1], O_RDONLY, 0777);
	if (pipex->fd_1 == -1)
		exit_program(pipex, "Error opening fd_1\n", 2);
	pipex->fd_2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_2 == -1)
		exit_program(pipex, "Error opening fd_2\n", 2);
	pipex->cmd_1 = ft_split(argv[2], ' ');
	pipex->cmd_2 = ft_split(argv[3], ' ');
}

char	*get_path(t_pipex *pipex, char **env, char *cmd)
{
	int		i;
	char	*path;
	char	*full_path;
	char	**arr;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i] + 5);
		i++;
	}
	arr = ft_split(path, ':');
	free(path);
	full_path = add_cmd_to_path(arr, cmd);
	if (!full_path)
		exit_program(pipex, "Error adding the full path\n", 2);
	return (full_path);
}

char	*add_cmd_to_path(char **arr, char *cmd)
{
	char	**cmd_arr;
	char	*full_path;
	int		i;

	i = 0;
	full_path = NULL;
	cmd_arr = ft_split(cmd, ' ');
	while (arr[i])
	{
		arr[i] = ft_strjoin_gnl(arr[i], "/");
		full_path = ft_strjoin(arr[i], cmd_arr[0]);
		if (access(full_path, X_OK) == 0)
			return (free_arr(arr), free_arr(cmd_arr), full_path);
		free(full_path);
		i++;
	}
	return (free_arr(arr), free_arr(cmd_arr), NULL);
}
