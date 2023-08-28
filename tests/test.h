/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:53:15 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/18 15:14:43 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../inc/token.h"
# include "../inc/parser.h"
# include "../inc/env_init.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <assert.h>

void	test_num_of_arguments(void);
void 	print_tokenize_string(t_token **head);
char 	*type_text(t_type type);
void	print_cmd_table(t_token **head, t_cmd_table *cmd_table);
void	print_double_array(char **command);
void	assert_tests(void);
void	test_get_cmd_location(void);
void    test_count_cmd(void);
void	print_redirect(t_redirect *redirect_arr, unsigned int redirect_count);
void	test_count_redirect(void);

#endif