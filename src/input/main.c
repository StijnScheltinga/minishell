/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/30 14:47:23 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char	*input_string;
	t_token	*token_head;

	argc = 0;
	argv = NULL;
	envp = NULL;
	token_head = NULL;
	atexit(leaks);
	while (1)
	{
		input_string = readline(NULL);
		tokenize_string(input_string, &token_head);
		free(input_string);
		free_func(&token_head);
	}
	return (0);
}
