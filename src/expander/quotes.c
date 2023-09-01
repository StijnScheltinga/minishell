/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:39:10 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/01 18:22:30 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"

//if env variable is found expand to value, else delete variable from string
char    *expand_var_quotes(char *text, t_cmd_table *cmd_table)
{
    char    *expanded_string;
    int     i;
    int     start_sub;

    expanded_string = malloc(1 * sizeof(char));
    i = 0;
    start_sub = 0;
	expanded_string[0] = '\0';
    while (text[i])
    {
        if (text[i] == '$' && !ft_iswhitespace(text[i + 1]) && text[i + 1])
        {
            if ((i - start_sub) > 0)
                expanded_string = ft_strjoin_free(expanded_string, ft_substr(text, start_sub, (i - start_sub)));
            i += join_env_var(&text[i], &expanded_string, cmd_table);
            start_sub = i;
        }
		else
        	i++;
    }
	if (start_sub != i)
		expanded_string = ft_strjoin_free(expanded_string, ft_substr(text, start_sub, (i - start_sub)));
    free(text);
    return (expanded_string);
}

int join_env_var(char *var_name, char **expanded_string, t_cmd_table *cmd_table)
{
    char    *var_value;
    int     i;

    var_value = find_var_val(var_name, cmd_table);
    i = 1;
    if (var_value)
        *expanded_string = ft_strjoin_free(*expanded_string, var_value);
    while (var_name[i] && !ft_iswhitespace(var_name[i]) && var_name[i] != '$')
	{
		if (var_name[i] == '?')
		{
			i++;
			break ;
		}
        i++;
	}
    return(i);
}

//pass &text[i] where dollar sign is found
char    *find_var_val(char *var, t_cmd_table *cmd_table)
{
    t_env   *iterate;
    char    *var_name;

    iterate = cmd_table->env;
	get_var_name(var, &var_name);
    if (!ft_strncmp(var_name, "?", 1))
        return (ft_strdup(ft_itoa(cmd_table->latest_exit_code)));
    while (iterate != NULL)
    {
        if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)))
            return(ft_strdup(iterate->value));
        iterate = iterate->next;
    }
    return(NULL);
}
