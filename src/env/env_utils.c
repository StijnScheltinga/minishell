/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:26 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/19 11:48:22 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env_init.h"
#include "../../inc/env_utils.h"
#include "../../libft/libft.h"

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

	new = ft_malloc(sizeof(t_env));
	new->variable = get_env_variable(s);
	new->value = get_env_value(s);
	new->next = NULL;
	return (new);
}

int	lst_size(t_env **env_head)
{
	int		size;
	t_env	*env;

	size = 0;
	env = *env_head;
	while (env)
	{
		if (env->value)
			size++;
		env = env->next;
	}
	return (size);
}

void	lst_delone(t_env **env_head, char *variable)
{
	t_env	*tmp;
	t_env	*prev;

	tmp = *env_head;
	prev = NULL;
	while (tmp)
	{
		if (!ft_strncmp(tmp->variable, variable, ft_strlen(variable) + 1))
		{
			if (prev)
				prev->next = tmp->next;
			if (tmp->variable)
				free(tmp->variable);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
