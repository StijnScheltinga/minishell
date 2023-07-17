/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:06:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:43:11 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env_init.h"

static void	unset_cmd(t_env *env, char *arg)
{
	
}

void	unset(t_cmd_table *cmd_table, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
		return ;
	while (cmd[i])
		unset_cmd(cmd_table->env, cmd[i++]);
}