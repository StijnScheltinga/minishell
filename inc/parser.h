/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:51:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/17 13:18:31 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include "env_init.h"
# include <stdio.h>

typedef struct s_command {
	char			**single_cmd;
	unsigned int	num_of_arguments;
	char			*input_file;
	char			*output_file;
}	t_command;

typedef struct s_cmd_table {
	t_command		*cmd_arr;
	unsigned int	cmd_count;
	char			**envp;
	t_env			*env;
}	t_cmd_table;

t_cmd_table	*parse_tokens(t_token **head, char **envp);
t_cmd_table	*init_cmd_table(t_token **head, char **envp);
void		fill_cmd_arr(t_cmd_table *cmd_table, t_token **head);
char		**single_command(t_token **head, int num_of_arguments, int i);
int			grammar_check(t_token **head);
int			pipe_check(t_token **head);
void		io_files(t_cmd_table *cmd_table, t_token **head);

void		free_func_cmd_table(t_cmd_table *cmd_table, t_token **head);
int			num_of_arguments(t_token **head, int i);
t_token		*get_cmd_location(t_token **head, int i);

#endif