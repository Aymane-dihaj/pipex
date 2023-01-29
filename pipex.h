/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:16:05 by adihaj            #+#    #+#             */
/*   Updated: 2023/01/20 16:45:22 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <errno.h>
# include <string.h>

char	*get_path(char **env, char *arg);
void	print_error(char *name, char *err);
void	child_process2(int fd2, int fd[], char **av, char **env);
void	child_process(int fd1, int fd[], char **av, char **env);
void	ft_free(char **cmd);
void	run_program(char *arg, char **env);

#endif