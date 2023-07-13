/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:14:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:58:35 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "parser.h"
# include "env.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>

bool	is_builtin(char *arg);
void	execute_builtin(t_cmd_table *cmd_table, int cmd_index);

void	ms_echo(const char *str);
void	ms_cd(char *arg, char **envp);
void	ms_env(t_env *head);
void	ms_exit(char **arg);
void	ms_export(t_cmd_table *cmd_table, char **cmd);
void	ms_pwd(void);
void	ms_unset(t_cmd_table *cmd_table, char **cmd);

#endif