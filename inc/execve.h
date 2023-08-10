/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:40:25 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/08 12:15:39 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECVE_H
# define EXECVE_H

char	*get_paths(char **envp);
void	ft_execve(char **cmd, char **envp);
char	*get_right_path(char **paths, char **cmd);

#endif