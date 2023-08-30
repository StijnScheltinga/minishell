/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:47 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/31 00:08:24 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/signals.h"

#include <unistd.h>
#include <signal.h>

void	sign_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	sign_delimiter(void)
{
	signal(SIGINT, sign_interrupt_delimiter);
}

void	sign_init(void)
{
	signal(SIGINT, sign_interrupt);
	signal(SIGQUIT, SIG_IGN);
}

void	sign_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
