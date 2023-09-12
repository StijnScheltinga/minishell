/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:06:53 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/12 17:10:54 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env_init.h"

static void	free_node_content(t_env	*node)
{
	free(node->variable);
	if (node->value)
		free(node->value);
	free(node);
}

static void	unset_cmd(t_cmd_table *cmd_table, char *var)
{
	t_env	*env_head;
	t_env	*holder;

	env_head = cmd_table->env;
	while (env_head)
	{
		if (!ft_strncmp(env_head->variable, var, ft_strlen(var) + 1))
			break ;
		holder = env_head;
		env_head = env_head->next;
	}
	if (!env_head)
		return ;
	holder->next = env_head->next;
	free_node_content(env_head);
}

void	unset(t_cmd_table *cmd_table, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
		return ;
	while (cmd[i])
		unset_cmd(cmd_table, cmd[i++]);
	cmd_table->latest_exit_code = 0;
}
