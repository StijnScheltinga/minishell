/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:09 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 20:28:22 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

void	env(t_cmd_table *cmd_table, t_env **head)
{
	t_env	*env;

	env = *head;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->variable, env->value);
		env = env->next;
	}
	cmd_table->latest_exit_code = 0;
}
