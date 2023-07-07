/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:14:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/06 19:17:35 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>

bool	is_builtin(char *arg);
void	execute_builtin(char **arg);

void	ms_echo(const char *str);
// void	ms_cd(char *arg, char **envp);
// void	ms_env(char **envp);
// void	ms_exit(int error);
// void	ms_export(char **arg);
// void	ms_pwd(char **arg);
// void	ms_unset(envp);

#endif