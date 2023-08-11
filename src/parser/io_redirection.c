/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:45:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/11 14:04:44 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

//Only redirect to last file in the command
void	create_redirect_arr(t_command *single_cmd_info, t_token **head, int i)
{
	t_token		*start;
	int			redirect_count;

	start = get_cmd_location(head, i);
	redirect_count = count_redirect(start);
	if (redirect_count)
	{
		single_cmd_info->redirect_arr = malloc((redirect_count) * sizeof(t_redirect));
		single_cmd_info->redirect_count = redirect_count;
		fill_redirect_arr(single_cmd_info->redirect_arr, start);
	}
	else
		single_cmd_info->redirect_arr = NULL;
}

int	count_redirect(t_token *start)
{
	t_token	*iterate;
	int		redirect_count;

	iterate = start;
	redirect_count = 0;
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == INFILE || iterate->type == OUTFILE || iterate->type == APPEND)
			redirect_count++;
		iterate = iterate->next;
	}
	return (redirect_count);
}

void	fill_redirect_arr(t_redirect *redirect_arr, t_token *iterate)
{
	int	redirect_i;

	redirect_i = 0;
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == INFILE || iterate->type == OUTFILE || iterate->type == APPEND)
		{
			redirect_arr[redirect_i].type = iterate->type;
			redirect_arr[redirect_i].file_name = ft_strdup(iterate->text);
			redirect_i++;
		}
		iterate = iterate->next;
	}
}
