/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/01 16:55:59 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"
#include <stdio.h>

int	expand_env_var(char *str, t_token **head, t_env **env_list)
{
	t_env	*iterate;
	char	*var_name;
	int		i;

	iterate = *env_list;
	i = get_var_name(str, &var_name);
	if (!var_name[0])
		create_token(WORD, ft_strdup("$"), head);
	while (iterate != NULL && var_name[0])
	{
		if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)) && iterate->value)
		{
			create_token(WORD, ft_strdup(iterate->value), head);
			break ;
		}
		iterate = iterate->next;
	}
	if (!iterate)
		create_token(WORD, ft_strdup(""), head);
	free (var_name);
	return (i);
}

int	expand_exit_status(char *str, t_token **head, t_cmd_table *cmd_table)
{
	if (*(str + 1) == '?')
		create_token(WORD, ft_strdup(ft_itoa(cmd_table->latest_exit_code)), head);
	return (2);
}

int	get_var_name(char *str, char **var_name)
{
	int		i;

	i = 1;
    while (str[i] && !ft_iswhitespace(str[i]) && str[i] != '$')
        i++;
    *var_name = ft_substr(str, 1, (i - 1));
	return (i);
}
