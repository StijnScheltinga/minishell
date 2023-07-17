/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:11:48 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:28:59 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

static int	is_int(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i++]))
			return (0);
	}
	return (1);
}

void	ms_exit(char **arg)
{
	if (!arg[1])
		exit(0);
	if (!is_int(arg[1]))
	{
		dprintf(2, "moet nummer zijn\n");
		exit(255);
	}
	exit(ft_atoi(arg[1]));
}
