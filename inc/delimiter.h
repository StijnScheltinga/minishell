/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:06:28 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/13 13:57:25 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELIMTER_H
# define DELIMTER_H

# include "parser.h"

bool	del_is_input(t_redirect *redirect_arr, int redirect_count);
int 	delimiter(t_redirect *redirect_arr, int redirect_count, t_cmd_table *cmd_table);
void	delimiter_single_builtin(t_cmd_table *cmd_table);

#endif