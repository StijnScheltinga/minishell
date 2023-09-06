/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:45:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/05 17:43:42 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

# define READ 0
# define WRITE 1

#include <sys/types.h>

void	free_pipes_and_pids(int (*fd)[2], pid_t *pids, int cmd_count);

void	close_all_pipes(int (*fd)[2], int pipe_count);
void	redirect_first_cmd(int (*fd)[2], int pipe_count);
void	redirect_middle_cmd(int (*fd)[2], int cmd_index, int pipe_count);
void	redirect_last_cmd(int (*fd)[2], int pipe_count);

#endif