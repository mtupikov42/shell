/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:28:03 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:14:08 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution/execution.h"
#include "utils/shell_utils.h"
#include "utils/errors.h"
#include "builtins/builtins.h"
#include "libft.h"

static int	try_execute_builtin(const char **args)
{
	int i;

	i = 0;
	while (i < g_builtins_size)
	{
		if (ft_strcmp(g_builtins_names[i], args[0]) == 0)
		{
			return (g_builtin_funcs[i](args + 1));
		}
		++i;
	}
	return (NO_SUCH_BINARY);
}

int			execute_command(const char **args)
{
	int		status;

	if (!args)
		return (SUCCESS);
	status = try_execute_builtin(args);
	if (status != NO_SUCH_BINARY)
		return (print_error((char *)args[0], status));
	return (status);
}
