/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:47 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/29 18:23:45 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/signals.h"

#include <unistd.h>
#include <signal.h>

extern int	g_signumber;

bool	sig_check(void)
{
	if (g_signumber == SIGINT)
	{
		g_signumber = 0;
		return (true);
	}
	return (false);
}

void	sign_interrupt(int signum)
{
	g_signumber = signum;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sign_init(void)
{
	signal(SIGINT, sign_interrupt);
	signal(SIGQUIT, SIG_IGN);
}

void	sign_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	sign_delim(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrl_d(void)
{
	write(STDOUT_FILENO, "exit\n", 5);
	exit(0);
}
