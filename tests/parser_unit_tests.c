/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unit_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:52:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/13 14:30:16 by stijn            ###   ########.fr       */
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
	tokenize_string("ls | cat -c | jo jo jo > outfile < infile", &head);
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

void	test_get_cmd_location(void)
{
	t_token	*head;
	t_token	*iterate;

	head = NULL;
	tokenize_string("cat | wc -w | sws swa", &head);
	iterate = get_cmd_location(&head, 1);
	assert(ft_strncmp(iterate->text, "wc", 2) == 0);
	iterate = get_cmd_location(&head, 0);
	assert(ft_strncmp(iterate->text, "cat", 3) == 0);
	iterate = get_cmd_location(&head, 2);
	assert(ft_strncmp(iterate->text, "sws", 3) == 0);
	free_func_token(&head);
	tokenize_string("< infile > outfile cat | < infile wc -w | sws swa > outfile", &head);
	iterate = get_cmd_location(&head, 1);
	assert(ft_strncmp(iterate->text, "<", 1) == 0);
	iterate = get_cmd_location(&head, 0);
	assert(ft_strncmp(iterate->text, "<", 1) == 0);
	iterate = get_cmd_location(&head, 2);
	assert(ft_strncmp(iterate->text, "sws", 3) == 0);
	free_func_token(&head);
}
