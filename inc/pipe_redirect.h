/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redirect.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:48:56 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/07 15:16:35 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_REDIRECT_H
# define PIPE_REDIRECT_H

# include <unistd.h>

# define READ 0
# define WRITE 1

void	close_all_pipes(int (*fd)[2], int pipe_count);
void	redirect_first_cmd(int (*fd)[2], int pipe_count);
void	redirect_middle_cmd(int (*fd)[2], int cmd_index, int pipe_count);
void	redirect_last_cmd(int (*fd)[2], int pipe_count);

#endif