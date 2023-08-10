/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:48:56 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/10 15:34:57 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# include "parser.h"

# define READ 0
# define WRITE 1

void	close_unused_pipes(t_cmd_table *cmd_table, int (*fd)[2], int cmd_index);
void	close_all_pipes(int (*fd)[2], int pipe_count);


#endif