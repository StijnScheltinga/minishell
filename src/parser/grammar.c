/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:42:21 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/06 15:25:43 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

void	grammar_error(t_token **head)
{
	t_token	*iterate;

	iterate = *head;
	while (iterate != NULL)
	{
		
		iterate = iterate->next;
	}
}
