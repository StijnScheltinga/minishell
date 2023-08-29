/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/29 16:44:11 by sschelti         ###   ########.fr       */
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
	i = 1;
	while (str[i] && !ft_iswhitespace(str[i]) && str[i] != '$')
		i++;
	var_name = ft_substr(str, 1, i - 1);
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

//if env variable is found expand to value, else delete variable from string
char	*expand_var_quotes(char *text, t_env **env_list)
{
	char	*exp_str;
	int		len;
	int		i;
	int		j;

	len = find_var_length(text, env_list);
	exp_str = malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	while (text[i])
	{
		if (text[i] == '$' && !ft_iswhitespace(text[i + 1]) && text[i + 1])
		{
			j += fill_env_var(&text[i++], &exp_str[j], env_list);
			while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
				i++;
			continue;
		}
		exp_str[j] = text[i];
		j++;
		i++;
	}
	exp_str[j] = '\0';
	free(text);
	return (exp_str);
}

int	fill_env_var(char *text, char *exp_str, t_env **env_list)
{
	char	*var_val;
	int		i;

	var_val = find_var_val(text, env_list);
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

char	*find_var_val(char *text, t_env **env_list)
{
	t_env	*iterate;
	char	*var_name;
	int		i;

	iterate = *env_list;
	i = 1;
	while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
		i++;
	var_name = ft_substr(text, 1, i - 1);
	while (iterate != NULL)
	{
		if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)))
			return(iterate->value);
		iterate = iterate->next;
	}
	return(NULL);
}

int	find_var_length(char *text, t_env **env_list)
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
			var_value = find_var_val(&text[i], env_list);
			if (var_value)
				len += ft_strlen(var_value);
			i++;
			while (text[i] && !ft_iswhitespace(text[i]) && text[i] != '$')
				i++;
			continue;
		}
		i++;
		len++;
	}
	return (len);
}
