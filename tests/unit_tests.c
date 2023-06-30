/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:22:38 by sschelti          #+#    #+#             */
/*   Updated: 2023/06/29 17:32:31 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/token.h"
#include <stdio.h>
#include <assert.h>

void	leaks(void)
{
	system("leaks test");
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

void free_func(t_token *head)
{
	t_token *temp;
	t_token	*first;
	
	while (head != NULL)
	{
		first = head;
		temp = first->next;
		free(first);	
		head = temp;
	}
}

void print_tokenize_string(char *text)
{
	t_token		*head;
	t_token		*iterate;

	head = NULL;
	tokenize_string(text, &head);
	iterate = head;
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
	atexit (leaks);
	assert(ft_iswhitespace(' ') == true);
	assert(ft_iswhitespace('a') == false);
	print_tokenize_string("cat | sws_swa < infile");
	// print_tokenize_string("swea | ls > outfile jo");

	
}
