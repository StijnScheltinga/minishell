/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/19 13:29:06 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/execute.h"
#include "../../inc/signals.h"
#include "../../inc/builtin.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input_string;
	t_token		*token_head;
	t_cmd_table	*cmd_table;

	argv++;
	token_head = NULL;
	cmd_table = init_cmd_table(&token_head, envp);
	if (argc != 1)
		return (printf("can't accept multiple arguments\n"), 1);
	while (1)
	{
		sign_init();
		input_string = get_line(cmd_table->latest_exit_code);
		if (!input_string)
			continue ;
		cmd_table->input_string = input_string;
		if (!tokenize_string(input_string, cmd_table))
		{
			fill_cmd_table(cmd_table, &token_head);
			execute(cmd_table);
			free_func_cmd_table(cmd_table);
		}
		free_func_token(&token_head);
	}
	return (0);
}
