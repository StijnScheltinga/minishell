/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/07 13:53:38 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

t_cmd_table	*init_cmd_table(t_token **head)
{
	t_cmd_table	*cmd_table;

	cmd_table = malloc(sizeof(t_cmd_table));
	cmd_table->cmd_count = count_cmd(head);
	cmd_table->cmd_arr = malloc(count_cmd(head) * sizeof(t_command));
	fill_cmd_arr(cmd_table, head);
	return(cmd_table);
}

void	fill_cmd_arr(t_cmd_table *cmd_table, t_token **head)
{
	int	arg_n;
	int	i;

	i = 0;
	arg_n = 0;
	while (i != cmd_table->cmd_count)
	{
		arg_n = num_of_arguments(head, i);
		cmd_table->cmd_arr[i].num_of_arguments = arg_n;
		cmd_table->cmd_arr[i].single_cmd = single_command(head, arg_n, i);
		i++;
	}
}

char	**single_command(t_token **head, int num_of_arguments, int i)
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
	cmd = malloc((num_of_arguments + 1) * sizeof(char *));
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
