/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:38:27 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/29 18:12:07 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include "../../inc/token.h"
#include <stdio.h>

int	expand_exit_status(char *str, t_token **head)
{
	if (*(str + 1) == '?')
		create_token(WORD, ft_strdup("exit_code"), head);
	return (2);
}
