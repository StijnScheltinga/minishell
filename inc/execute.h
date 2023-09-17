/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:07:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/15 19:16:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "parser.h"

//EXECUTE
void	execute_multiple_cmd(t_cmd_table *cmd_table);
void	execute_single_cmd(t_cmd_table *cmd_table);
void	execute(t_cmd_table *cmd_table);

//UTILS
void	create_pid_array(t_cmd_table *cmd_table);
void	create_pipes(t_cmd_table *cmd_table);
void	wait_for_children(t_cmd_table *cmd_table);

#endif