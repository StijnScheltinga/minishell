/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:11:48 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/06 13:18:46 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define NUMERIC 0
#define TOO_MANY 1

static void	exit_error(char *s, int error)
{
	if (error == NUMERIC)
	{
		ft_putstr_fd("exit\nexit: ", STDERR_FILENO);
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	if (error == TOO_MANY)
	{
		ft_putstr_fd("exit\nexit: ", STDERR_FILENO);
		ft_putstr_fd("too many arguments\n", STDERR_FILENO);
	}
}

static void	is_in_range(char *s)
{
	unsigned long long	val;
	int					i;

	val = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	if (val > (unsigned long long)__LONG_LONG_MAX__ + 1 && s[0] == '-')
		exit_error(s, NUMERIC);
	if (val > __LONG_LONG_MAX__ && s[0] != '-')
		exit_error(s, NUMERIC);
	if (i > 19 && (s[0] != '+' && s[0] != '-'))
		exit_error(s, NUMERIC);
	if (i > 20)
		exit_error(s, NUMERIC);
}

static void	is_numeric(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		i++;
		if (!s[i])
			exit_error(s, NUMERIC);
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			exit_error(s, NUMERIC);
	}
}

static long long	ll_atoi(char *s)
{
	long long	val;
	long long	sign;
	int			i;

	val = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i])
	{
		val = val * 10 + (s[i] - '0');
		i++;
	}
	return (val * sign);
}

void	ms_exit(char **arg, t_cmd_table *cmd_table)
{
	long long	exit_code;

	if (!arg[1])
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit(0);
	}
	if (!arg[1][0])
		exit_error(arg[1], NUMERIC);
	exit_code = ll_atoi(arg[1]);
	is_numeric(arg[1]);
	is_in_range(arg[1]);
	if (arg[2])
	{
		exit_error(NULL, TOO_MANY);
		cmd_table->latest_exit_code = 1;
	}
	else
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit((int)(ll_atoi(arg[1]) % (long long)256));
	}
}
