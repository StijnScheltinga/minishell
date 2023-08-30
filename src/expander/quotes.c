/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:39:10 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/30 16:12:05 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"

//if env variable is found expand to value, else delete variable from string
char	*expand_var_quotes(char *text, t_cmd_table *cmd_table)
{
	char	*expanded_string;
	int		len;
	int		i;
	int		j;

	len = find_var_length(text, cmd_table);
	expanded_string = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	while (text[i])
	{
		if (text[i] == '$' && !ft_iswhitespace(text[i + 1]) && text[i + 1])
		{
			j += fill_env_var(&text[i++], &expanded_string[j], cmd_table);
			if (text[i] == '?')
			{
				i++;
				continue;
			}
			while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
				i++;
			continue;
		}
		expanded_string[j] = text[i];
		j++;
		i++;
	}
	expanded_string[j] = '\0';
	free(text);
	return (expanded_string);
}

int	fill_env_var(char *text, char *exp_str, t_cmd_table *cmd_table)
{
	char	*var_val;
	int		i;

	var_val = find_var_val(text, cmd_table);
	i = 0;
	if (!var_val)
		return (0);
	while (var_val[i])
	{
		exp_str[i] = var_val[i];
		i++;
	}
	return (i);
}

int	find_var_length(char *text, t_cmd_table *cmd_table)
{
	int		i;
	int		len;
	char	*var_value;

	i = 0;
	len = 0;
	while (text[i])
	{
		if (text[i] == '$' && !ft_iswhitespace(text[i + 1]) && text[i + 1])
		{
			var_value = find_var_val(&text[i], cmd_table);
			if (var_value)
				len += ft_strlen(var_value);
			i++;
			if (text[i] == '?')
			{
				i++;
				continue;
			}
			while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
				i++;
			continue;
		}
		i++;
		len++;
	}
	return (len);
}

char	*find_var_val(char *text, t_cmd_table *cmd_table)
{
	t_env	*iterate;
	char	*var_name;
	int		i;

	iterate = cmd_table->env;
	i = 1;
	while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
		i++;
	var_name = ft_substr(text, 1, i - 1);
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
