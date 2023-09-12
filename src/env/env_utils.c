/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:26 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/12 13:40:15 by sschelti         ###   ########.fr       */
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

static int	lst_size(t_env **env_head)
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

char	**linked_list_to_double_array(t_env **env_head)
{
	char	**ret;
	t_env	*env;
	int		i;
	int		size;

	size = lst_size(env_head);
	ret = ft_malloc(sizeof(char *) * (size + 1));
	i = 0;
	env = *env_head;
	while (i < size)
	{
		if (env->value)
		{
			ret[i] = ft_strjoin_with_char(env->variable, env->value, '=');
			i++;
		}
		env = env->next;
	}
	ret[i] = NULL;
	return (ret);
}
