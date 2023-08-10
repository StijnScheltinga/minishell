/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:06:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/18 17:33:54 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env_init.h"

static void	free_node_content(t_env	*node)
{
	free(node->variable);
	free(node->value);
	free(node);
}

static void	unset_cmd(t_cmd_table *cmd_table, char *var)
{
	t_env	*env_head;
	t_env	*holder;

	holder = env_head;
	env_head = cmd_table->env;
	while (env_head)
	{
		if (!ft_strncmp(env_head->variable, var, ft_strlen(var)))
			break ;
		holder = env_head;
		env_head = env_head->next;
	}
	if (!env_head)
	{
		free(var);
		return ;
	}
	holder->next = env_head->next;
	free_node_content(env_head);
	free(var);
}

void	unset(t_cmd_table *cmd_table, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
		return ;
	while (cmd[i])
		unset_cmd(cmd_table, get_env_variable(cmd[i++]));
}
