/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:48:04 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/25 19:03:33 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/signals.h"

char *get_line(void)
{
	static char	*input_string;

	if (input_string)
	{
		free(input_string);
		input_string = NULL;
	}
	input_string = readline("ms: ");
	if (!input_string)
		ctrl_d();
	if (input_string[0] == '\0')
		return(NULL);
	add_history(input_string);
	return (input_string);
}
