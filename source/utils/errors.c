/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:53:09 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:17:15 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/errors.h"
#include "utils/shell_utils.h"
#include "libft.h"

int		print_error(char *binary_name, int status)
{
	if (status == NO_SUCH_BINARY)
		ft_printf("No such binary: %s\n", binary_name);
	else if (status == NO_SUCH_ENV)
		ft_printf("No such environment variable exists\n");
	else if (status == SETENV_SYNTAX_ERROR)
		ft_printf("./Usage: setenv ['KEY=VALUE' or 'KEY = VALUE']\n");
	else if (status == UNSETENV_ARGS_ERROR)
		ft_printf("./Usage: unsetenv [KEY ...]\n");
	return (status);
}
