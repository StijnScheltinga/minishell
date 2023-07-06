/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:51:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/06 13:31:45 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include <stdio.h>

typedef struct s_command {
	char	**single_cmd;
}	t_command;

typedef struct s_cmd_table {
	t_command	*cmd_arr;
	char		*input_file;
	char		*output_file;
}	t_cmd_table;

t_cmd_table	*parse_tokens(t_token **head);
t_cmd_table	*init_cmd_table(t_token **head);
void		fill_cmd_arr(t_command *cmd_arr, t_token **head);
char		**single_command(t_token **head, int i);
int			num_of_arguments(t_token **head, int i);
void		check_redirection(t_token **head);
void		free_func_cmd_table(t_cmd_table *cmd_table, t_token **head);

#endif