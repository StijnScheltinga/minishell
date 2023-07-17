/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:50:14 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 12:03:13 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/parser.h"
#include "../../inc/env_utils.h"

static void	export_error_check(void)
{
	//NEED TO MAKE
}

static void	print_export(t_cmd_table *cmd_table)
{
	t_env	*env;

	env = cmd_table->env;
	while (env)
	{
		if (env->value)
			printf("declare -x %s\"%s\"\n", env->variable, env->value);
		else
			printf("declare -x %s\n", env->variable);
		env = env->next;
	}
}

static void	create_export_variable(t_cmd_table *cmd_table, char *arg)
{
	t_env	*new;

	new = env_lstnew(arg);
	export_error_check();
	env_lstadd_back(cmd_table->env, new);
	print_export(cmd_table);
}


void	export(t_cmd_table *cmd_table, char **cmd)
{
	int	i;

	i = 1;
	if (!cmd[i])
		print_export(cmd_table);
	else
	{
		while (cmd[i])
			create_export_variable(cmd_table, cmd[i++]);
	}
}