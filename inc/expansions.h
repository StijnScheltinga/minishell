/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:18:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/09/04 13:38:47 by sschelti         ###   ########.fr       */
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
int 	join_env_var(char *var_name, char **expanded_string, t_cmd_table *cmd_table);
int		find_var_val(char *var, char **var_val, t_cmd_table *cmd_table);
int		get_var_name(char *str, char **var_name);

#endif