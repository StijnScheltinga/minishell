/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:09 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/17 15:26:58 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

void	env(t_env **head)
{
	t_env	*env;

	env = *head;
	while (env)
	{
		printf("%s=%s\n", env->variable, env->value);
		env = env->next;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	env(envp);
// }