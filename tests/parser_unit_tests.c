/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unit_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:52:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/11 12:49:12 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_num_of_arguments(void)
{
	t_token *head;

	head = NULL;
	tokenize_string("ls | cat -c | jo jo jo > outfile < infile", &head);
	assert(num_of_arguments(&head, 0) == 1);
	assert(num_of_arguments(&head, 1) == 2);
	assert(num_of_arguments(&head, 2) == 3);
	free_func_token(&head);
	tokenize_string(" | ls | cat -c | jo jo jo > outfile < infile", &head);
	assert(num_of_arguments(&head, 0) == 1);
	assert(num_of_arguments(&head, 1) == 2);
	assert(num_of_arguments(&head, 2) == 3);
	free_func_token(&head);
	tokenize_string("ls -la", &head);
	assert(num_of_arguments(&head, 0) == 2);
	free_func_token(&head);
}

void	print_cmd_table(t_token **head, t_cmd_table *cmd_table)
{
	int			i;

	i = 0;
	printf("command table:\n");
	while (i != count_cmd(head))
	{
		print_double_array(cmd_table->cmd_arr[i].single_cmd);
		i++;
	}
	printf("infile: %s\n", cmd_table->input_file);
	printf("outfile: %s\n", cmd_table->output_file);
}

void	print_double_array(char **command)
{
	int i;
	
	i = 0;
	while (command[i] != NULL)
	{
		printf("%s, ", command[i]);
		i++;
	}
	printf("\n");
}
