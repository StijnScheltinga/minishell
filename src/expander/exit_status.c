/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:38:27 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/30 11:40:35 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/expansions.h"
#include <stdio.h>

int	expand_exit_status(char *str, t_token **head, t_cmd_table *cmd_table)
{
	if (*(str + 1) == '?')
		create_token(WORD, ft_strdup(ft_itoa(cmd_table->latest_exit_code)), head);
	return (2);
}
