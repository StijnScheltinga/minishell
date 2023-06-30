/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/29 16:13:38 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input_string;
	t_token	*token_head;

	argc = 0;
	argv = NULL;
	envp = NULL;
	token_head = NULL;
	while (1)
	{
		input_string = readline(NULL);
		tokenize_string(input_string, &token_head);
	}
	return (0);
}
