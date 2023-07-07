/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:07:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/07 13:26:09 by sschelti         ###   ########.fr       */
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

void	execute_with_child(int (*fd)[2], int cmd_index);
void	execute_multiple_cmd();
void	execute_single_cmd();
void	execute_commands(void);
void	execute(t_cmd_table *cmd_table);

#endif