/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:24:49 by stijn             #+#    #+#             */
/*   Updated: 2023/09/04 17:26:30 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/error.h"

void    malloc_error(t_cmd_table *cmd_table)
{
    free_func_token(cmd_table->token_head);
	free_func_cmd_table(cmd_table, cmd_table->token_head);
	free(cmd_table);
}
