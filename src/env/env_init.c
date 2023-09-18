/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:38:00 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/18 16:56:38 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/env_init.h"
#include "../../inc/env_utils.h"
#include "../../libft/libft.h"

char	*get_env_variable(char *s)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (s[len] != '=' && s[len])
		len++;
	if (!s[len])
		return (ft_strdup(s));
	new = ft_malloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

// + 1 in return because '=' is not part of the value
char	*get_env_value(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	if (!s[i])
		return (NULL);
	return (ft_strdup(s + i + 1));
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
