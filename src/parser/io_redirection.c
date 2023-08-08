/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:45:23 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/08 16:47:53 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

//Only redirect to last file in the command
void	count_and_fill_io_files(t_command *single_cmd_info, t_token **head, int i)
{
	t_token	*iterate;
	t_token	*start;
	int		in;
	int		out;
	
	iterate = get_cmd_location(head, i);
	start = iterate;
	in = 0;
	out = 0;
	single_cmd_info->input_files = NULL;
	single_cmd_info->output_files = NULL;
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == INFILE)
			in++;
		else if (iterate->type == OUTFILE)
			out++;
		iterate = iterate->next;
	}
	if (in > 0)
		single_cmd_info->input_files = fill_io_array(single_cmd_info->input_files, start, INFILE, in);
	if (out > 0)
		single_cmd_info->output_files = fill_io_array(single_cmd_info->output_files, start, OUTFILE, out);
}

char	**fill_io_array(char **io_file_array, t_token *iterate, t_type type, int n)
{
	int	i;

	i = 0;
	io_file_array = malloc((n + 1) * sizeof(char *));
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == type)
		{
			io_file_array[i] = ft_strdup(iterate->text);
			i++;
		}
		iterate = iterate->next;
	}
	io_file_array[i] = NULL;
	return (io_file_array);
}
