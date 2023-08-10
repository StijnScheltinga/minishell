/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:50:14 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/18 13:42:33 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/parser.h"
#include "../../inc/env_utils.h"
#include "../../inc/env_init.h"

static void	export_error_check(void)
{
	//NEED TO MAKE
}

static void	print_export(t_cmd_table *cmd_table)
{
	t_env	*env_head;

	env_head = cmd_table->env;
	while (env_head)
	{
		if (env_head->value)
			printf("declare -x %s=\"%s\"\n", env_head->variable, env_head->value);
		else
			printf("declare -x %s\n", env_head->variable);
		env_head = env_head->next;
	}
}

static bool	export_var_exist(t_cmd_table *cmd_table, char *var)
{
	t_env	*env_head;

	env_head = cmd_table->env;
	while (env_head)
	{
		if (!ft_strncmp(env_head->variable, var, ft_strlen(var)))
		{
			free(var);
			return (true);
		}
		env_head = env_head->next;
	}
	free(var);
	return (false);
}

static void	replace_var_value(t_cmd_table *cmd_table, char *arg)
{
	t_env	*env_head;
	char	*var;

	env_head = cmd_table->env;
	var = NULL;
	while (env_head)
	{
		var = get_env_variable(arg);
		if (!ft_strncmp(env_head->variable, var, ft_strlen(env_head->variable)))
		{
			env_head->value = get_env_value(arg);
			free(var);
			break ;
		}
		free(var);
		env_head = env_head->next;
	}
}

static void	create_export_variable(t_cmd_table *cmd_table, char *arg)
{
	t_env	*new;

	export_error_check();
	if (export_var_exist(cmd_table, get_env_variable(arg)))
		replace_var_value(cmd_table, arg);
	else
	{
		new = env_lstnew(arg);
		env_lstadd_back(cmd_table->env, new);
	}
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