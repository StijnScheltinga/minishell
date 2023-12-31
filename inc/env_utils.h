/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:39:58 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/19 11:48:03 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

void	env_lstadd_back(t_env *lst, t_env *new);
t_env	*env_lstlast(t_env *lst);
t_env	*env_lstnew(char *s);
int		lst_size(t_env **env_head);
void	lst_delone(t_env **env_head, char *variable);

#endif