/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/15 16:02:02 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/execute.h"

void	leaks(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	char		*input_string;
	t_token		*token_head;
	t_cmd_table	*cmd_table;

	argc = 0;
	argv = NULL;
	token_head = NULL;
	cmd_table = malloc(sizeof(t_cmd_table));
	cmd_table->envp = envp;
	cmd_table->env = env_to_linkedlist(envp);
	// atexit(leaks);
	while (1)
	{
		input_string = get_line();
		if (!input_string)
			continue ;
		if (!tokenize_string(input_string, &token_head, &cmd_table->env))
		{
			parse_tokens(cmd_table, &token_head);
			execute(cmd_table);
			free_func_cmd_table(cmd_table, &token_head);
		}
		free_func_token(&token_head);
	}
	return (0);
}
