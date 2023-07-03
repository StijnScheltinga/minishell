/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:51:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/07/03 17:32:59 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"

typedef struct s_command {
	char	**single_cmd;
}	t_command;

typedef struct s_cmd_table {
	t_command	*cmd_arr;
	char		*input_file;
	char		*output_file;
}	t_cmd_table;

void	parse_tokens(t_token **head);
void	init_cmd_table(t_cmd_table *cmd_table, t_token **head);
void	fill_cmd_arr(t_command *cmd_arr, t_token **head);
char	**single_command(t_token **head, int i);
int		num_of_arguments(t_token **head, int i);
void	check_redirection(t_token **head);

#endif