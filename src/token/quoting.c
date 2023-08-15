/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:54:07 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/15 14:51:04 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/error.h"

//return amount of char within quote
int	handle_quotes(char *str, t_token **head)
{
	int		i;
	char	*text;

	i = 1;
	while (str[i] && str[i] != str[0])
		i++;
	text = ft_substr(str, 1, i - 1);
	create_token(WORD, text, head);
	return (i + 1);
}

