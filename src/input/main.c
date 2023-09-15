/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:10:05 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/14 21:06:59 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/token.h"
#include "../../inc/parser.h"
#include "../../inc/execute.h"
#include "../../inc/signals.h"
#include "../../inc/builtin.h"

static void	print_token(t_token **head)
{
	t_token	*iterate;
	int		i;

	iterate = *head;
	i = 1;
	while (iterate != NULL)
	{
		printf("token %d: %s\n", i, iterate->text);
		iterate = iterate->next;
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char		*input_string;
	t_token		*token_head;
	t_cmd_table	*cmd_table;

	argc++;
	argv++;
	token_head = NULL;
	cmd_table = init_cmd_table(&token_head, envp);
	while (1)
	{
		sign_init();
		input_string = get_line(cmd_table->latest_exit_code);
		if (!input_string)
			continue ;
		cmd_table->input_string = input_string;
		if (!tokenize_string(input_string, cmd_table))
		{
			print_token(&token_head);
			fill_cmd_table(cmd_table, &token_head);
			execute(cmd_table);
			free_func_cmd_table(cmd_table);
		}
		free_func_token(&token_head);
	}
	return (0);
}
