/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:51:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/11 12:34:20 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include <stdio.h>

typedef struct s_command {
	char			**single_cmd;
	unsigned int	num_of_arguments;
}	t_command;

typedef struct s_cmd_table {
	t_command		*cmd_arr;
	char			*input_file;
	char			*output_file;
	unsigned int	cmd_count;
	char			**envp;
}	t_cmd_table;

t_cmd_table	*parse_tokens(t_token **head, char **envp);
t_cmd_table	*init_cmd_table(t_token **head, char **envp);
void		fill_cmd_arr(t_cmd_table *cmd_table, t_token **head);
char		**single_command(t_token **head, int num_of_arguments, int i);
void		grammar_check(t_token **head);
void		pipe_check(t_token **head);
void		io_files(t_cmd_table *cmd_table, t_token **head);

int			num_of_arguments(t_token **head, int i);
void		check_redirection(t_token **head);
void		free_func_cmd_table(t_cmd_table *cmd_table, t_token **head);

#endif