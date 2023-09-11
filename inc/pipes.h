/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 16:06:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# define READ 0
# define WRITE 1

#include "parser.h"

#include <sys/types.h>

void	free_pids_and_pipes(t_cmd_table *cmd_table);
void	close_all_pipes(t_cmd_table *cmd_table);
void	redirect_first_cmd(t_cmd_table *cmd_table, t_command *cmd);
void	redirect_middle_cmd(t_cmd_table *cmd_table, t_command *cmd, int cmd_index);
void	redirect_last_cmd(t_cmd_table *cmd_table, t_command *cmd);

void	close_pipes(t_cmd_table *cmd_table, int pipe_index, int pipe_to_close);

#endif