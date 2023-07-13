/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:03:09 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:13:07 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

void	ms_env(t_env *head)
{
	while (head)
	{
		printf("%s%s\n", head->variable, head->value);
		head = head->next;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	ms_env(envp);
// }