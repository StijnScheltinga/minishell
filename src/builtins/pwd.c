/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:39 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/11 20:26:04 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

//does not return error code but prints the error

void	pwd(t_cmd_table *cmd_table)
{
	char	buffer[FILENAME_MAX];

	if (getcwd(buffer, FILENAME_MAX))
		printf("%s\n", buffer);
	else
		perror("pwd");
	cmd_table->latest_exit_code = 0;
}
