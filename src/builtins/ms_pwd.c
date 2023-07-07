/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:39 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/06/27 18:15:26 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

//does not return error code but prints the error

void	ms_pwd(void)
{
	char	buffer[FILENAME_MAX];

	if (getcwd(buffer, FILENAME_MAX))
		printf("%s\n", buffer);
	else
		perror("pwd");
}
