/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/06 17:09:10 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

static char *get_path(char **env, char *cmd);

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	t_pipex *pipex;
	
	pipex = malloc(sizeof(t_pipex));

	pipex->cmd_1 = get_path(envp, argv[1]);
	return 0;
}

static char	*get_path(char **env, char *cmd)
{
	int		i;
	char	*path;
	char	**arr;
	char	**cmdarr;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i] + 5);
		i++;
	}
	arr = ft_split(path, ':');
	cmdarr = ft_split(cmd, ' ');
	for (int j = 0; arr[j]; j++)
	{
		char *temp;
		arr[j] = ft_strjoin(arr[j], "/");
		temp = ft_strjoin(arr[j], cmdarr[0]);
		if (access(temp, X_OK) == 0)
			return temp;
	}
	return 0;
}