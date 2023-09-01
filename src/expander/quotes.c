/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:39:10 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/31 19:16:05 by stijn            ###   ########.fr       */
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

    expanded_string = NULL;
    i = 0;
    start_sub = 0;
    while (text[i])
    {
        if (text[i] == '$' && !ft_iswhitespace(text[i + 1]) && text[i + 1])
        {
            if (expanded_string && (i - start_sub) > 0)
                expanded_string = ft_strjoin(expanded_string, ft_substr(text, start_sub, (i - start_sub)));
            else if (!expanded_string)
                expanded_string = ft_substr(text, start_sub, i);
            i += join_env_var(&text[i], &expanded_string, cmd_table);
            start_sub = i;
        }
		else
        	i++;
    }
	if (start_sub != i && expanded_string)
		expanded_string = ft_strjoin(expanded_string, ft_substr(text, start_sub, (i - start_sub)));
	if (!expanded_string)
		expanded_string = ft_strdup(text);
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
        *expanded_string = ft_strjoin(*expanded_string, var_value);
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
    int     i;

    iterate = cmd_table->env;
    i = 1;
    while (var[i] && !ft_iswhitespace(var[i]) && var[i] != '$')
        i++;
    var_name = ft_substr(var, 1, (i - 1));
    if (!ft_strncmp(var_name, "?", 1))
        return (ft_itoa(cmd_table->latest_exit_code));
    while (iterate != NULL)
    {
        if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)))
            return(iterate->value);
        iterate = iterate->next;
    }
    return(NULL);
}
