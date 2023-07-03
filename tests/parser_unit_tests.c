/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_unit_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:52:47 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/03 18:01:52 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_num_of_arguments(t_token **head)
{
	tokenize_string("ls | cat -a | wc -l -w > outfile", head);
	assert(num_of_arguments(head, 0) == 1);
	assert(num_of_arguments(head, 1) == 2);
	assert(num_of_arguments(head, 2) == 3);
	free_func(head);
}