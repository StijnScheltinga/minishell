/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:40:25 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/15 18:21:21 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECVE_H
# define EXECVE_H

# include "env_init.h"

char	*get_paths(char **envp);
void	ft_execve(char **cmd, t_env **env_head);
char	*get_right_path(char **paths, char **cmd);

#endif