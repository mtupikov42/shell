/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:19:37 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:09:53 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/builtins.h"
#include "utils/shell_utils.h"
#include "shell.h"
#include "libft.h"

int	bt_exit(const char **args)
{
	(void)args;
	g_shell.is_running = false;
	return (SUCCESS);
}

int	bt_help(const char **args)
{
	int		i;

	(void)args;
	ft_printf("These builtins are avaiable:\n");
	i = 0;
	while (i < 7)
	{
		ft_printf(" %i) %s\n", i, g_builtins_names[i]);
		++i;
	}
	return (SUCCESS);
}
