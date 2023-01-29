/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:59:12 by adihaj            #+#    #+#             */
/*   Updated: 2023/01/17 20:13:02 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process2(int fd2, int fd[], char **av, char **env)
{
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 == -1)
		print_error(av[4], strerror(errno));
	dup2(fd2, 1);
	close(fd[1]);
	dup2(fd[0], 0);
	run_program(av[3], env);
}
