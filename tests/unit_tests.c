/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 17:24:17 by stijn            ###   ########.fr       */
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
	test_get_cmd_location();
	test_count_cmd();
}

int	main(void)
{
	t_token 	*head;
	t_cmd_table	*cmd_table;
	char		*text;
	
	head = NULL;
	cmd_table = NULL;
	text = "< infile ls -la > outfile | cat -a | wc -l -w > outfile";
	atexit(leaks);
	assert_tests();
	tokenize_string(text, &head);
	print_tokenize_string(text, &head);
	cmd_table = parse_tokens(&head, NULL);
	print_cmd_table(&head, cmd_table);
	free_func_cmd_table(cmd_table, &head);
	free_func_token(&head);
}
