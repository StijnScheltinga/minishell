/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:18:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/30 15:26:18 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "token.h"
# include "parser.h"

typedef struct s_token	t_token;

int		expand_env_var(char *str, t_token **head, t_env **env_list);
char	*expand_var_quotes(char *text, t_cmd_table *cmd_table);
char	*find_var_val(char *text, t_cmd_table *cmd_table);
int		find_var_length(char *text, t_cmd_table *cmd_table);
int		fill_env_var(char *text, char *exp_str, t_cmd_table *cmd_table);
int		expand_exit_status(char *str, t_token **head, t_cmd_table *cmd_table);

#endif