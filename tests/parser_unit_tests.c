/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unit_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:52:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/04 18:02:12 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_num_of_arguments(t_token **head)
{
	assert(num_of_arguments(head, 0) == 1);
	assert(num_of_arguments(head, 1) == 2);
	assert(num_of_arguments(head, 2) == 3);
}

void	print_cmd_table(t_token **head, t_cmd_table *cmd_table)
{
	int			i;

	i = 0;
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
