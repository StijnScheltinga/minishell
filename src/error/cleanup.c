/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:24:49 by stijn             #+#    #+#             */
/*   Updated: 2023/09/06 14:22:01 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/error.h"

void    malloc_error(void *ptr, void *ptr2, t_cmd_table *cmd_table)
{
    if (ptr)
    {
        free (ptr);
        ptr = NULL;
    }
    if (ptr2)
    {
        free (ptr2);
        ptr2 = NULL;
    }
    //only frees when token list is actually made
	free (cmd_table->input_string);
    free_func_token(cmd_table->token_head);
	free_func_cmd_table(cmd_table);
	free(cmd_table);
    exit(EXIT_FAILURE);
}
