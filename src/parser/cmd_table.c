/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/04 18:23:28 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_cmd_table	*init_cmd_table(t_token **head)
{
	t_cmd_table	*cmd_table;

	cmd_table = malloc(sizeof(t_cmd_table)); 
	cmd_table->cmd_arr = malloc(count_cmd(head) * sizeof(t_command));
	fill_cmd_arr(cmd_table->cmd_arr, head);
	return(cmd_table);
}

void	fill_cmd_arr(t_command *cmd_arr, t_token **head)
{
	int	i;

	i = 0;
	while (i != count_cmd(head))
	{
		cmd_arr[i].single_cmd = single_command(head, i);
		i++;
	}
}

char	**single_command(t_token **head, int i)
{
	t_token	*iterate;
	char	**cmd;
	int		cmd_n;
	int		j;

	iterate = *head;
	cmd_n = 0;
	j = 0;
	while (iterate != NULL && i != cmd_n)
	{
		if (iterate->type == PIPE)
			cmd_n++;
		iterate = iterate->next;
	}
	cmd = malloc((num_of_arguments(head, i) + 1) * sizeof(char *));
	while (iterate != NULL && iterate->type == WORD)
	{
		cmd[j] = ft_strdup(iterate->text);
		j++;
		iterate = iterate->next;
	}
	cmd[j] = NULL;
	return (cmd);
}

int	num_of_arguments(t_token **head, int i)
{
	t_token *iterate;
	int		num_of_arguments;
	int		cmd_n;

	iterate = *head;
	num_of_arguments = 0;
	cmd_n = 0;
	while (iterate != NULL)
	{
		if (iterate->type == PIPE)
			cmd_n++;
		if (cmd_n == i)
		{
			if (iterate->type == PIPE)
				iterate = iterate->next;
			while (iterate != NULL && iterate->type == WORD)
			{
				num_of_arguments++;
				iterate = iterate->next;
			}
			return (num_of_arguments);
		}
		iterate = iterate->next;
	}
	return (0);
}
