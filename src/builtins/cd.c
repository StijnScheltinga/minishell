/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/08/24 19:15:32 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"
#include "../../inc/env_init.h"

#include <errno.h>
#include <string.h>

//not implementing error code

static char	*get_home(t_env **env_head)
{
	size_t	i;
	char	*ret;
	t_env	*iter;

	i = 0;
	ret = NULL;
	iter = *env_head;
	while (iter)
	{
		if (ft_strncmp(iter->variable, "HOME", 5) == 0)
			break ;
		iter = iter->next;
	}
	if (!iter)
		printf("cd: HOME not set\n");
	else if (iter->variable)
		ret = iter->value;
	return (ret);
}

//uses envp from seperate int main -> no other envp yet

static char	*find_right_path(char *arg, t_env **env_head)
{
	char	*path;

	path = NULL;
	if (arg == NULL || ft_strncmp(arg, "~", sizeof(arg)) == 0)
		path = get_home(env_head);
	else
		path = arg;
	return (path);
}

//does not return error code but prints the error

void	cd(char *arg, t_env **env_head)
{
	char	*path;

	path = find_right_path(arg, env_head);
	if (!path)
		return ;
	if (chdir(path))
		printf("cd: %s: %s\n", path, strerror(errno));
}

// int main(int argc, char **argv, char **envp)
// {
// 	cd(NULL, envp);
// }