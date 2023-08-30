/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimiter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:06:28 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/29 20:49:30 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELIMTER_H
# define DELIMTER_H

# include "parser.h"

bool	check_if_del_is_input(t_redirect *redirect_arr, int redirect_count);
int 	delimiter(t_redirect *redirect_arr, int redirect_count);

#endif