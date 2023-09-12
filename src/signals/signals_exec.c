/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:33:22 by alex              #+#    #+#             */
/*   Updated: 2023/09/12 17:20:32 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/main.h"
#include "../../inc/signals.h"

#include <unistd.h>
#include <stdlib.h>

void	sign_interrupt(int signum)
{
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sign_interrupt_delimiter(int signum)
{
	close(STDOUT_FILENO);
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void	ctrl_d(int latest_exit_code)
{
	write(STDERR_FILENO, "exit\n", 5);
	exit(latest_exit_code);
}
