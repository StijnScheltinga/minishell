/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:14:55 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/21 14:06:37 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../libft/libft.h"
# include "parser.h"

bool	is_builtin(char *arg);
void	execute_builtin(t_cmd_table *cmd_table, int cmd_index, int io[2]);
void	builtin_single_cmd(t_cmd_table *cmd_table);
void	exec_delimiter_single_builtin(char *eof);

void	echo(t_cmd_table *cmd_table, char **arg);
void	cd(char **arg, t_env **env_head, t_cmd_table *cmd_table);
void	env(t_cmd_table *cmd_table, t_env **head);
void	ms_exit(char **arg, t_cmd_table *cmd_table, int io[2]);
void	export(t_cmd_table *cmd_table, char **cmd);
void	pwd(t_cmd_table *cmd_table);
void	unset(t_cmd_table *cmd_table, char **cmd);

char	*get_home_cmd_table(t_env **env_head);

#endif