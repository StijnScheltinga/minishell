/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:07:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/06/23 17:17:04 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "builtin.h"

void	execute_command(void);
void	executing(void);

#endif