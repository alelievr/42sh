/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:16:13 by alelievr          #+#    #+#             */
/*   Updated: 2016/04/01 19:59:33 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int			check_executable(char *name)
{
	if (!name)
		return (BINARY_NOT_FILE);
	if (access(name, F_OK) == 0 && !is_dir(name))
	{
		if (access(name, X_OK))
			return (BINARY_OK);
		else
			return (BINARY_NOT_EXECUTABLE);
	}
	else if (is_builtin(name))
		return (BINARY_OK);
	else if (get_binhash_path(hashstring(name)))
		return (BINARY_OK);
	else
		return (BINARY_NOT_IN_PATH);
	return (BINARY_NOT_FILE);
}

static int			check_command_executables(t_command *c, int print)
{
	size_t		i;
	int			r;

	i = -1;
	while (c)
	{
		if (!c->list || ((r = check_executable(c->list->bin))))
		{
			if ((r == BINARY_NOT_FILE || r == BINARY_NOT_IN_PATH) && print)
				ft_printf("%s: command not found\n", c->list->bin);
			else if (r == BINARY_NOT_EXECUTABLE && print)
				ft_printf("%s: can't execute file\n", c->list->bin);
			return (COMMAND_FAILED);
		}
		c = c->next;
	}
	return (COMMAND_OK);
}

static int			exe_create_pipes_fork(t_command *c)
{
	pid_t	pid;
	int		res;

	while (c->next != NULL)
	{
		if ((pid = fork()) == -1)
			return (COMMAND_FAILED);
		if (pid == 0)
		{
			execute_operator(c->list, c, P_CHILD);
			if (c->list->bin)
				execute_binary(c->list->bin, c->list->av_bin, g_env);
			else
				ft_printf("null executable !\n");
		}
		else
			execute_operator(c->list, c, P_FATHER);
		c = c->next;
	}
	waitpid(pid, &res, 0);
	return (res);
}

int					execute_command(t_command *c)
{
	if (check_command_executables(c, 1))
		return (COMMAND_FAILED);
	return (exe_create_pipes_fork(c));
}
