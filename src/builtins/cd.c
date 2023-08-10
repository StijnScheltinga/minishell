/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/07/18 11:54:45 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

#include <errno.h>
#include <string.h>

//not implementing error code

static char	*get_home(char **envp)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "HOME=", 5))
			break ;
		i++;
	}
	if (envp[i] == NULL)
		printf("cd: HOME not set\n");
	else if (ft_strlen(envp[i]) > 5)
		ret = envp[i] + 5;
	return (ret);
}

//uses envp from seperate int main -> no other envp yet

static char	*find_right_path(char *arg, char **envp)
{
	char	*path;

	path = NULL;
	if (arg == NULL || ft_strncmp(arg, "~", sizeof(arg)) == 0)
		path = get_home(envp);
	else
		path = arg;
	return (path);
}

//does not return error code but prints the error

void	cd(char *arg, char **envp)
{
	char	*path;

	path = find_right_path(arg, envp);
	if (chdir(path))
		printf("cd: %s: %s\n", path, strerror(errno));
}

// int main(int argc, char **argv, char **envp)
// {
// 	cd(NULL, envp);
// }