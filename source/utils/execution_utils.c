/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 13:47:37 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 20:24:09 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/execution_utils.h"
#include "utils/shell_utils.h"
#include "execution/execution.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

static int	get_size_without_empty_lines(char **args)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (args[i])
	{
		if (!command_contain_only_whitespaces(args[i]))
			++size;
		++i;
	}
	return (size);
}

bool	command_contain_only_whitespaces(char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (!ft_is_whitespace(cmd[i]))
				return (false);
			++i;
		}
	}
	return (true);
}

char	**trim_arguments(char **args)
{
	int		i;
	int		j;
	char	**new_args;

	new_args = NULL;
	if (args && ft_strsplit_count((const char **)args) > 0)
	{
		i = 0;
		j = 0;
		new_args = (char **)ft_memalloc(sizeof(char *) *
			(get_size_without_empty_lines(args) + 1));
		while (args[i])
		{
			if (!command_contain_only_whitespaces(args[i]))
			{
				new_args[j] = ft_strtrim(args[i]);
				++j;
			}
			++i;
		}
	}
	return (new_args);
}

int		try_execute_directly(const char **args)
{
	int status;

	status = PERMISIION_DENIED;
	if (access(args[0], X_OK) == 0)
		status = fork_and_execute((char *)args[0], args);
	return (status);
}