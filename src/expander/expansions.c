/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/12 17:14:52 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"
#include "../../inc/error.h"
#include <stdio.h>

int	expand_env_var(char *str, t_cmd_table *cmd_table)
{
	char	*var_value;
	char	*var_name;
	int		len_var_name;

	len_var_name = get_var_name(str, &var_name);
	var_value = find_var_value(var_name, cmd_table);
	if (var_value)
		create_token(WORD, var_value, cmd_table);
	return (len_var_name);
}

int	expand_exit_status(char *str, t_cmd_table *cmd_table)
{
	if (*(str + 1) == '?')
		create_token(WORD, ft_itoa(cmd_table->latest_exit_code), cmd_table);
	return (2);
}

int	get_var_name(char *str, char **var_name)
{
	int		i;

	i = 1;
	while (str[i] && !ft_iswhitespace(str[i])
		&& str[i] != '$' && str[i - 1] != '?')
		i++;
	*var_name = ft_substr(str, 1, (i - 1));
	return (i);
}

//if value of variable is found it returns it else it returns NULL
char	*find_var_value(char *var_name, t_cmd_table *cmd_table)
{
	t_env	*i;
	char	*var_val;

	i = cmd_table->env;
	if (!var_name[0])
		var_val = ft_strdup("$");
	else if (!ft_strncmp(var_name, "?", 1))
		var_val = ft_itoa(cmd_table->latest_exit_code);
	else
	{
		while (i != NULL)
		{
			if (!ft_strncmp(i->variable, var_name, ft_strlen(var_name) + 1))
			{
				var_val = ft_strdup(i->value);
				break ;
			}
			i = i->next;
		}
	}
	if (!i)
		var_val = NULL;
	free (var_name);
	return (var_val);
}
