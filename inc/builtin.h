/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:14:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/01 14:56:07 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "parser.h"
# include "env_init.h"

bool	is_builtin(char *arg);
void	execute_builtin(t_cmd_table *cmd_table, int cmd_index);

void	echo(char **arg);
void	cd(char *arg, t_env **env_head, t_cmd_table *cmd_table);
void	env(t_env **head);
void	ms_exit(char **arg);
void	export(t_cmd_table *cmd_table, char **cmd);
void	pwd(void);
void	unset(t_cmd_table *cmd_table, char **cmd);

#endif