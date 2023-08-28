/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:44:23 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/25 19:01:41 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/error.h"

static int	export_error(char *arg)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	return (1);
}

int	export_error_check(char *arg)
{
	int	i;

	i = 1;
	if (!arg[0])
		return (export_error(arg));
	if (ft_isdigit(arg[0]) || (!ft_isalpha(arg[0]) && arg[0] != '_'))
		return (export_error(arg));
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (export_error(arg));
		i++;
	}
	return (0);
}
