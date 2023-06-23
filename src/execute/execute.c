/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:40:51 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/06/23 17:17:15 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/execute.h"

// execute a builtin if found, otherwise execute command

void	execute_command(void);
{
	
}

/*restoring stdin and stdout after executing one or more command(s)*/

void	executing(void)
{
	int stdin_holder;
	int stdout_holder;

	stdin_holder = dup(STDIN_FILENO);
	stdout_holder = dup(STDOUT_FILENO);
	execute_command();
	dup2(stdin_holder, STDIN_FILENO);
	dup2(stdout_holder, STDOUT_FILENO);
}

// int main(void)
// {
// 	executing();
// 	return (0);
// }
