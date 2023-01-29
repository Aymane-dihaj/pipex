/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:15:51 by adihaj            #+#    #+#             */
/*   Updated: 2023/01/20 16:45:22 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char **cmd, char **env)
{
	char	*path;

	if (!ft_strchr(cmd[0], '/'))
	{
		path = get_path(env, cmd[0]);
		execve(path, cmd, env);
		print_error(cmd[0], "command not found");
	}
	else
	{
		path = cmd[0];
		if (-1 == access(path, X_OK))
			print_error(path, strerror(errno));
		else
			execve(path, cmd, env);
	}
}

void	run_program(char *arg, char **env)
{
	char	**cmd;
	int		i;

	i = 0;
	if (*arg)
	{
		cmd = ft_split(arg, ' ');
		execute(cmd, env);
		ft_free(cmd);
	}
	else
		print_error("", "command not found");
	exit(127);
}

void	make_pipe(int fd1, int fd2, char **av, char **env)
{
	int		fd[2];
	int		id;
	int		id2;

	id = 1;
	pipe(fd);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
		print_error(av[4], strerror(errno));
	if (fd1 != -1)
		id = fork();
	if (id == 0)
		child_process(fd1, fd, av, env);
	id2 = fork();
	if (id2 == 0)
	{
		child_process2(fd2, fd, av, env);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(id2, NULL, 0);
	waitpid(id, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	int	file1;
	int	file2;

	file1 = 0;
	file2 = 0;
	if (ac == 5)
		make_pipe(file1, file2, av, env);
	else
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	return (1);
}
