/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:38:00 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 12:31:40 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env_init.h"
#include "../../inc/env_utils.h"
#include "../../libft/libft.h"

#include <stdlib.h>
#include <stdio.h>

char	*get_env_variable(char *s)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (s[len] != '=' && s[len])
		len++;
	if (!s[len])
		return (s);
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

// + 1 in return because the '=' is not the value
char	*get_env_value(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	if (!s[i])
		return (NULL);
	return (s + i + 1);
}

t_env	*env_to_linkedlist(char **envp)
{
	int		i;
	t_env	*env_list;
	t_env	*new;

	env_list = env_lstnew(envp[0]);
	i = 1;
	while (envp[i])
	{
		new = env_lstnew(envp[i]);
		env_lstadd_back(env_list, new);
		i++;
	}
	return (env_list);
}
