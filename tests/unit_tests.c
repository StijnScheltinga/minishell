/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 14:28:36 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	leaks(void)
{
	system("leaks -s test");
}

void	assert_tests(void)
{
	test_num_of_arguments();
}

int	main(void)
{
	t_token 	*head;
	t_cmd_table	*cmd_table;
	char		*text;
	
	head = NULL;
	cmd_table = NULL;
	text = "ls -la -l -w -c | cat -a | wc -l -w > outfile";
	atexit(leaks);
	test_get_cmd_location();
	test_num_of_arguments();
	// tokenize_string(text, &head);
	// print_tokenize_string(text, &head);
	// cmd_table = parse_tokens(&head, NULL);
	// print_cmd_table(&head, cmd_table);
	// free_func_cmd_table(cmd_table, &head);
	// free_func_token(&head);
}
