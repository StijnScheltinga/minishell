/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:09 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/21 13:51:59 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

void	env(t_env **head)
{
	t_env	*env;

	env = *head;
	while (env)
	{
		if (env->value)
			printf("%s=%s\n", env->variable, env->value);
		env = env->next;
	}
}
