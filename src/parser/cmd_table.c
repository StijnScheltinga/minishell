/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/12 14:56:24 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"
#include "../../inc/execute.h"
#include "../../inc/error.h"
#include "../../inc/builtin.h"

t_cmd_table	*init_cmd_table(t_token **head, char **envp)
{
	t_cmd_table	*cmd_table;

	cmd_table = ft_malloc(sizeof(t_cmd_table));
	cmd_table->env = env_to_linkedlist(envp);
	cmd_table->latest_exit_code = 0;
	cmd_table->cmd_count = 0;
	cmd_table->token_head = head;
	cmd_table->cmd_arr = NULL;
	cmd_table->home = get_home_cmd_table(&cmd_table->env);
	return (cmd_table);
}

void	fill_cmd_table(t_cmd_table *cmd_table, t_token **head)
{
	int	cmd_n;

	cmd_n = count_cmd(head);
	cmd_table->cmd_count = cmd_n;
	cmd_table->cmd_arr = ft_malloc(cmd_n * sizeof(t_command));
	create_pipes(cmd_table);
	create_pid_array(cmd_table);
	fill_cmd_arr(cmd_table, head);
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
		create_redir_arr(&(cmd_table->cmd_arr[i]), head, i);
		i++;
	}
}

char	**single_command(t_token **head, int num_of_arguments, int i)
{
	t_token	*iterate;
	char	**cmd;
	int		j;

	iterate = get_cmd_location(head, i);
	j = 0;
	cmd = ft_malloc((num_of_arguments + 1) * sizeof(char *));
	while (iterate != NULL && iterate->type != PIPE)
	{
		if (iterate->type == WORD)
		{
			cmd[j] = ft_strdup(iterate->text);
			j++;
		}
		iterate = iterate->next;
	}
	cmd[j] = NULL;
	return (cmd);
}
