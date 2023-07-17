/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:01 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/17 11:26:03 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

//code assumes possible -n option is given within the whole string
//does not implement $variables and $?

void	echo(const char *str)
{
	size_t	i;
	bool	n_option;

	i = 0;
	n_option = false;
	if (str[i++] == '-')
	{
		while (str[i] == 'n')
			i++;
		if (str[i] == ' ' || str[i] == '\0')
			n_option = true;
		if (str[i] == ' ')
			i++;
	}
	if (n_option == false)
		i = 0;
	while (str[i])
		write(STDIN_FILENO, &str[i++], 1);
	if (n_option == false)
		write(STDIN_FILENO, "\n", 1);
}

// int main(void)
// {
// 	echo(NULL, envp);
// }