/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:53:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/06 14:04:43 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../inc/token.h"
# include "../inc/parser.h"
# include <stdio.h>
# include <assert.h>

void	test_num_of_arguments(void);
void 	print_tokenize_string(char *text, t_token **head);
char 	*type_text(t_type type);
void	print_cmd_table(t_token **head, t_cmd_table *cmd_table);
void	print_double_array(char **command);
void	assert_tests(void);

#endif