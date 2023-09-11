/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:50:14 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/05 13:31:53 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/parser.h"
#include "../../inc/env_utils.h"
#include "../../inc/env_init.h"
#include "../../inc/error.h"

#include <unistd.h>

static void	print_export(t_cmd_table *cmd_table)
{
	t_env	*env_head;

	env_head = cmd_table->env;
	while (env_head)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(env_head->variable, STDOUT_FILENO);
		if (env_head->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(env_head->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
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
	{
		print_export(cmd_table);
		return ;
	}
	while (cmd[i])
	{
		if (export_error_check(cmd[i]))
		{
			cmd_table->latest_exit_code = 1;
			i++;
		}
		else
		{
			create_export_variable(cmd_table, cmd[i]);
			cmd_table->latest_exit_code = 0;
			i++;
		}
	}
}
