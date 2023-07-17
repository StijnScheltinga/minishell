/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:14:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:42:40 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "parser.h"
# include "env_init.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>

bool	is_builtin(char *arg);
void	execute_builtin(t_cmd_table *cmd_table, int cmd_index);

void	echo(const char *str);
void	cd(char *arg, char **envp);
void	env(t_env *head);
void	ms_exit(char **arg);
void	export(t_cmd_table *cmd_table, char **cmd);
void	pwd(void);
void	unset(t_cmd_table *cmd_table, char **cmd);

#endif