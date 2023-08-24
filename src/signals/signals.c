/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:47 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/24 18:57:21 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/signals.h"

#include <unistd.h>
#include <signal.h>

void	sign(int signum)
{
	printf("signum=%d\n", signum);
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}		

void	sign_init(void)
{
	signal(SIGINT, sign);
	signal(SIGQUIT, SIG_IGN);
}
