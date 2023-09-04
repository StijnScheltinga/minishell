/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/04 14:38:13 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"
#include <stdio.h>

int	expand_env_var(char *str, t_token **head, t_cmd_table *cmd_table)
{
	char	*var_value;
	int		len_var_name;

	len_var_name = find_var_val(str, &var_value, cmd_table);
	printf("%d ", len_var_name);
	printf("%s\n", var_value);	
	if (!var_value)
		create_token(WORD, ft_strdup(""), head);
	else
		create_token(WORD, var_value, head);
	return (len_var_name);
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

//if value of variable is found it returns it else it returns NULL
int	find_var_val(char *var, char **var_val, t_cmd_table *cmd_table)
{
    t_env   *iterate;
    char    *var_name;
	int		var_name_len;

	*var_val = NULL;
    iterate = cmd_table->env;
	var_name_len = get_var_name(var, &var_name);
	if (!var_name[0])
		*var_val = ft_strdup("$");
    else if (!ft_strncmp(var_name, "?", 1))
        *var_val = ft_strdup(ft_itoa(cmd_table->latest_exit_code));
	else
	{
		while (iterate != NULL)
		{
			if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)))
				*var_val = ft_strdup(iterate->value);
			iterate = iterate->next;
		}
	}
	free (var_name);
    return(var_name_len);
}
