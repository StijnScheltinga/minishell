/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:18:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/08/18 12:25:07 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include "token.h"

typedef struct s_token	t_token;

int		expand_env_var(char *str, t_token **head, t_env **env_list);
char	*expand_var_quotes(char *text, t_env **env_list);
char	*find_var_val(char *text, t_env **env_list);
int		find_var_length(char *text, t_env **env_list);
int		fill_env_var(char *text, char *exp_str, t_env **env_list);

#endif