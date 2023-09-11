/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:18:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/11 17:59:05 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "token.h"
# include "parser.h"

typedef struct s_token	t_token;

int		expand_env_var(char *str, t_token **head, t_cmd_table *cmd_table);
char	*expand_var_quotes(char *text, t_cmd_table *cmd_table);
int		expand_exit_status(char *str, t_token **head, t_cmd_table *cmd_table);
int 	join_env_var(char *str, char **expanded_string, t_cmd_table *cmd_table);
char	*find_var_value(char *var_name, t_cmd_table *cmd_table);
int		get_var_name(char *str, char **var_name, t_cmd_table *cmd_table);
char    *add_char(char *expanded_string, char *text, int i, t_cmd_table *cmd_table);
char    *get_quote_text(char *str, t_cmd_table *cmd_table);

#endif