/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:36:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/18 17:21:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_INIT_H
# define ENV_INIT_H

typedef struct s_env{
	char			*variable;
	char			*value;
	struct s_env	*next;
}					t_env;

char	*get_env_variable(char *s);
char	*get_env_value(char *s);
t_env	*env_to_linkedlist(char **envp);
char	**linked_list_to_double_array(t_env **env_head);

#endif