/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:05:39 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/30 23:36:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

//SIG EXEC-
void	sign_interrupt(int signum);
void	sign_interrupt_delimiter(int signum);
void	ctrl_d(void);

//SIG INIT
void	sign_child(void);
void	sign_delimiter(void);
void	sign_init(void);
void	sign_ignore(void);

#endif