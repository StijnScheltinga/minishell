/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:39:10 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/11 18:00:40 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"
#include "../../inc/error.h"

char    *get_quote_text(char *str, t_cmd_table *cmd_table)
{
    char    *text;
    int     i;

    i = 1;
    while (str[i] != str[0] && str[i])
		i++;
	if (!str[i])
		return (NULL);
	text = ft_substr(str, 1, i - 1);
	if (!text)
		malloc_error(NULL, NULL, cmd_table);
	if (str[0] == '"')
		text = expand_var_quotes(text, cmd_table);
    return (text);
}

//if env variable is found expand to value, else delete variable from string
char    *expand_var_quotes(char *text, t_cmd_table *cmd_table)
{
    char    *expanded_string;
    int     i;

    expanded_string = malloc(1 * sizeof(char));
    if (!expanded_string)
        malloc_error(text, NULL, cmd_table);
    expanded_string[0] = '\0';
    i = 0;
    while (text[i])
    {
        if (text[i] != '$' || (text[i] == '$' && !text[i + 1]))
            expanded_string = add_char(expanded_string, text, i, cmd_table);
        if ((text[i] == '$' && text[i + 1]))
            i += join_env_var(&text[i], &expanded_string, cmd_table);
		else
        	i++;
    }
    free(text);
    return (expanded_string);
}

char    *add_char(char *expanded_string, char *text, int i, t_cmd_table *cmd_table)
{
    char    *added_char;

    added_char = ft_substr(text, i, 1);
    if (!added_char)
        malloc_error(text, expanded_string, cmd_table);
    expanded_string = ft_strjoin_free(expanded_string, added_char);
    if (!expanded_string)
        malloc_error(text, NULL, cmd_table);
    return (expanded_string);
}

int join_env_var(char *str, char **expanded_string, t_cmd_table *cmd_table)
{
    char    *var_value;
	char	*var_name;
    int     var_name_len;

	var_name_len = get_var_name(str, &var_name, cmd_table);
    var_value = find_var_value(var_name, cmd_table);
    if (var_value)
    {
        *expanded_string = ft_strjoin_free(*expanded_string, var_value);
        if (!(*expanded_string))
            malloc_error(*expanded_string, var_value, cmd_table);
    }
    return(var_name_len); 
}
