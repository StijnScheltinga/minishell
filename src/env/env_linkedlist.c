/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_linkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:43:36 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/11 18:05:39 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env_linkedlist.h"

char	*get_env_variable(char *s)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (s[len] != '=')
		len++;
	i = 0;
	new = malloc(sizeof(char) * len + 2);
	while (i < len + 1)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_env_value(char *s)
{
	while (*s != '=')
		s++;
	s++;
	return (s);
}

void	env_to_linkedlist()
{
	int		i;
	t_env	*env_list;
	t_env	*new;

	env_list = ft_lstnew(envp[i]);
	i = 0;
	while (envp[i])
	{
		new = ft_lstnew(envp[i]);
		ft_lstadd_back(env_list, new);
		i++;
	}
}

void	ft_lstadd_back(t_env *lst, t_env *new)
{
	t_env	*tmp;

	if (!lst)
	{
		lst = new;
		return ;
	}
	tmp = ft_lstlast(lst);
	tmp->next = new;
}


t_env	*ft_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


t_env	*ft_lstnew(char *s)
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
