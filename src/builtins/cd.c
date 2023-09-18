/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:48:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2023/09/18 14:13:32 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

#include <errno.h>
#include <string.h>

//not implementing error code

static void	error_msg(t_cmd_table *cmd_table, char *arg, char *error_msg)
{
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	cmd_table->latest_exit_code = 1;
}

char	*get_home(t_env **env_head, t_cmd_table *cmd_table)
{
	char	*ret;
	t_env	*iter;

	ret = NULL;
	iter = *env_head;
	while (iter)
	{
		if (ft_strncmp(iter->variable, "HOME", 5) == 0)
			break ;
		iter = iter->next;
	}
	if (!iter)
	{
		write(STDERR_FILENO, "cd: HOME not set\n", 17);
		cmd_table->latest_exit_code = 1;
	}
	else
		ret = iter->value;
	return (ret);
}

//uses envp from seperate int main -> no other envp yet

static char	*find_right_path(char **arg, t_env **env_head, t_cmd_table *cmd_tab)
{
	char	*path;

	path = NULL;
	if (arg[1] == NULL)
		path = get_home(env_head, cmd_tab);
	else if (ft_strncmp(arg[1], "~", sizeof(arg[1])) == 0)
		path = cmd_tab->home;
	else
		path = arg[1];
	return (path);
}

//does not return error code but prints the error

void	cd(char **arg, t_env **env_head, t_cmd_table *cmd_table)
{
	char	*path;

	if (arg[1])
	{
		if (arg[2])
		{
			error_msg(cmd_table, arg[0], "too many arguments");
			return ;
		}
	}
	path = find_right_path(arg, env_head, cmd_table);
	if (!path)
		return ;
	if (chdir(path))
		error_msg(cmd_table, arg[1], strerror(errno));
	else
		cmd_table->latest_exit_code = 0;
}
