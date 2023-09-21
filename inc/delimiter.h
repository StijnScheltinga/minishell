/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:06:28 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/21 15:01:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELIMITER_H
# define DELIMITER_H

# include "parser.h"

bool	del_is_input(t_redirect *redirect_arr, int redirect_count);
int		delimiter(t_redirect *redir_arr, int redir_n, t_cmd_table *cmd_table);
int 	delimiter_count(t_redirect *redirect_arr, int redirect_count);
void	delimiter_single_builtin(t_cmd_table *cmd_table, int io[2]);

#endif