/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:58 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:34:55 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

void	env_lstadd_back(t_env *lst, t_env *new);
t_env	*env_lstlast(t_env *lst);
t_env	*env_lstnew(char *s);

#endif