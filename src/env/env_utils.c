/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:26 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/13 16:52:59 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env.h"
#include "../../inc/env_utils.h"
#include <stdlib.h>

void	env_lstadd_back(t_env *lst, t_env *new)
{
	t_env	*tmp;

	if (!lst)
	{
		lst = new;
		return ;
	}
	tmp = env_lstlast(lst);
	tmp->next = new;
}


t_env	*env_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_env	*env_lstnew(char *s)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->variable = get_env_variable(s);
	new->value = get_env_value(s);
	new->next = NULL;
	return (new);
}
