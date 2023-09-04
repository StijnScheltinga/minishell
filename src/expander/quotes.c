/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:39:10 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/04 14:31:30 by sschelti         ###   ########.fr       */
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
        if (text[i] == '$' && text[i + 1])
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
    int     var_name_len;

    var_name_len = find_var_val(var_name, &var_value, cmd_table);
	printf("%d, %s\n", var_name_len, var_value);
    if (var_value)
        *expanded_string = ft_strjoin_free(*expanded_string, var_value);
    return(var_name_len); 
}
