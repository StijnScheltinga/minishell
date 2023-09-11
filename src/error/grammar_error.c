/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:05:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/04 17:09:18 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

int	syntax_error(char *token, t_cmd_table *cmd_table)
{
	printf("syntax error near unexpected token: '%s'\n", token);
	cmd_table->latest_exit_code = 258;
	return (1);
}
