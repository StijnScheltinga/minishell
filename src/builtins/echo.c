/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:01 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/17 17:30:53 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

#include <stdbool.h>

static bool	n_option(char *s)
{
	int	i;

	if (!s)
		return (false);
	if (s[0] != '-' || s[1] != 'n')
		return (false);
	i = 2;
	while (s[i])
	{
		if (s[i++] != 'n')
			return (false);
	}
	return (true);
}

void	echo(char **arg)
{
	int	i;

	i = 1;
	if (!arg[i])
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	while (n_option(arg[i]) == true)
		i++;
	while (arg[i])
	{
		ft_putstr_fd(arg[i++], STDOUT_FILENO);
		if (arg[i])
			write(STDOUT_FILENO, " ", 1);
	}
	if (n_option(arg[1]) == false)
		write(STDOUT_FILENO, "\n", 1);
}


// int main(void)
// {
// 	echo(NULL, envp);
// }