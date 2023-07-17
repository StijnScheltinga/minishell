/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:07:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 12:38:29 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"

void	execute_with_child(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index);
void	execute_multiple_cmd(t_cmd_table *cmd_table);
void	execute_single_cmd(t_cmd_table *cmd_table);
void	execute(t_cmd_table *cmd_table);

#endif