/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/30 14:48:06 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"
#include <stdio.h>
#include <assert.h>

void	leaks(void)
{
	system("leaks -s test");
}

char *type_text(t_type type)
{
	if (type == PIPE)
		return ("PIPE");
	else if (type == REDIRECT)
		return ("REDIRECT");
	else
		return ("WORD");
}

void print_tokenize_string(char *text, t_token **head)
{
	t_token		*iterate;
	
	tokenize_string(text, head);
	iterate = *head;
	printf("input: %s\n", text);
	while (iterate != NULL)
	{
		printf("%s, %s\n", iterate->text, type_text(iterate->type));
		iterate = iterate->next;
	}
	free_func(head);
}

int	main(void)
{
	t_token *head;
	
	head = NULL;
	atexit (leaks);
	assert(ft_iswhitespace(' ') == true);
	assert(ft_iswhitespace('a') == false);
	print_tokenize_string("cat | sws_swa < infile", &head);
	print_tokenize_string("swea | ls > outfile jo", &head);
	print_tokenize_string("cat |cat | cat | ls \n| 			wc -w", &head);
	print_tokenize_string("AADASD", &head);
}
