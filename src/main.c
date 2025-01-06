/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeirele <jmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:59:26 by jmeirele          #+#    #+#             */
/*   Updated: 2025/01/06 16:34:57 by jmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

static void get_path(char **env, char *str);

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	get_path(envp, argv[1]);
	return 0;
}

static void	get_path(char **env, char *str)
{
	int		i;
	char	*path;
	char	**arr;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_strdup(env[i] + 5);
		i++;
	}
	arr = ft_split(path, ':');
	for (int j = 0; arr[j]; j++)
	{
		char *temp;
		arr[j] = ft_strjoin(arr[j], "/");
		temp = ft_strjoin(arr[j], str);
		if (access(temp, X_OK) == 0)
			printf("%s\n", arr[j]);
	}
	// printf("%s\n", path);
}