/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/17 18:22:22 by sschelti         ###   ########.fr       */
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
	while (str[i] && !ft_iswhitespace(str[i]))
		i++;
	var_name = ft_substr(str, 1, i);
	while (iterate != NULL)
	{
		if (!ft_strncmp(iterate->variable, var_name, ft_strlen(var_name)))
		{
			create_token(WORD, iterate->value, head);
			break ;
		}
		iterate = iterate->next;
	}
	if (!iterate)
		create_token(WORD, "", head);
	free (var_name);
	return (i);
}

//if env variable is found expand to value, else delete variable from string
char	*expand_var_quotes(char *text, t_env **env_list)
{
	find_var_length(text, env_list);
	return (NULL);
}

char	*find_var_val(char *text, t_env **env_list)
{
	t_env	*iterate;
	char	*var_name;
	int		i;

	iterate = *env_list;
	i = 1;
	while (text[i] && !ft_iswhitespace(text[i]))
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
		if (text[i] == '$')
		{
			var_value = find_var_val(&text[i], env_list);
			if (var_value)
				len += ft_strlen(var_value);
			while (text[i] && !ft_iswhitespace(text[i]))
				i++;
			continue;
		}
		i++;
		len++;
	}
	dprintf(1, "string len expanded: %d\n", len);
	return (len);
}
