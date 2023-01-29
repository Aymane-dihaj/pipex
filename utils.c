/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:28:02 by adihaj            #+#    #+#             */
/*   Updated: 2023/01/20 16:45:22 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_path(char *path, char *arg)
{
	char	*exe;
	char	*path;
	int		i;

	i = 0;
	while (path[i] && path[i] != ':')
		i++;
	path = malloc(sizeof(char) * i + 2);
	if (!path)
		exit(0);
	ft_bzero(path, i + 2);
	i = 0;
	while (*path && *path != ':')
	{
		path[i] = *path;
		path++;
		i++;
	}
	path[i] = '/';
	exe = ft_strjoin(path, arg);
	free(path);
	return (exe);
}

char	*get_path(char **env, char *arg)
{
	int		i;
	char	*path;
	char	*exe;

	i = 0;
	path = NULL;
	while (env[i] && ft_strncmp("path=", env[i], 5))
		i++;
	if (!env[i])
		return (arg);
	path = env[i] + 5;
	while (*path)
	{
		if (path == env[i] + 5 || *path == ':')
		{
			exe = parse_path(path + !(path == env[i] + 5), arg);
			if (!access(exe, F_OK))
				return (exe);
			free(exe);
		}
		path++;
	}
	return (arg);
}

void	print_error(char *name, char *err)
{
	ft_putstr_fd("pipex ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	exit(1);
}

void	ft_free(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

void	child_process(int fd1, int fd[], char **av, char **env)
{
	fd1 = open(av[1], O_RDONLY);
	if (fd1 == -1)
		print_error(av[1], strerror(errno));
	dup2(fd1, 0);
	close(fd[0]);
	dup2(fd[1], 1);
	run_program(av[2], env);
}
