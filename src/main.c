/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/09 17:37:14 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

static char	*get_path(char **env, char *cmd);
static char	*add_cmd_to_path(char **arr, char *cmd);

int	main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;

	pipex = init_struct();
	if (argc == 5)
	{
		check_args_and_set(pipex, argv);
		pipex->cmd_1 = get_path(envp, argv[2]);
		pipex->cmd_2 = get_path(envp, argv[3]);
		exit_program(pipex, "success\n", 1);
	}
	else
		exit_program(pipex, "Please provide only 4 arguments\n", 2);
	return 0;
}

static char	*get_path(char **env, char *cmd)
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
	return (full_path);
}

static char	*add_cmd_to_path(char **arr, char *cmd)
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
			return(free_arr(arr), free_arr(cmd_arr), full_path);
		free(full_path);
		i++;
	}
	return(free_arr(arr), free_arr(cmd_arr), NULL);
}
