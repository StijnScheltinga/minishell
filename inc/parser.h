/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:51:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/05 13:13:24 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "token.h"
# include "env_init.h"
# include <stdio.h>

typedef struct s_command t_command;

typedef struct s_redirect t_redirect;

typedef struct s_redirect {
	char	*file_name;
	t_type	type;
}	t_redirect;

typedef struct s_command {
	char			**single_cmd;
	unsigned int	num_of_arguments;
	t_redirect		*redirect_arr;
	int				redirect_count;
}	t_command;

typedef struct s_cmd_table {
	t_command		*cmd_arr;
	unsigned int	cmd_count;
	int				latest_exit_code;
	char			*input_string;
	t_token			**token_head;
	t_env			*env;
}	t_cmd_table;

t_cmd_table	*init_cmd_table(t_token **token_head, char **envp);
void		fill_cmd_table(t_cmd_table *cmd_table, t_token **head);
void		fill_cmd_arr(t_cmd_table *cmd_table, t_token **head);
char		**single_command(t_token **head, int num_of_arguments, int i);

int			grammar_check(t_token **head, t_cmd_table *cmd_table);
int			double_metachar_check(t_token **head, t_cmd_table *cmd_table);

void		create_redirect_arr(t_command *single_cmd_info, t_token **head, int i);
int			count_redirect(t_token *start);
void		fill_redirect_arr(t_redirect *redirect_arr, t_token *iterate);

void		free_func_cmd_table(t_cmd_table *cmd_table);
void		free_redirect_array(t_redirect *redirect_arr, unsigned int redirect_count);
void		free_double_array(char	**double_array);
int			num_of_arguments(t_token **head, int i);
t_token		*get_cmd_location(t_token **head, int i);

#endif