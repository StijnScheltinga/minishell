/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:36:18 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:42:08 by aolde-mo         ###   ########.fr       */
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

#endif