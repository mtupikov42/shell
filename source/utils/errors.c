/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:53:09 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 15:54:56 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/errors.h"
#include "utils/shell_utils.h"
#include "libft.h"

void	print_error(const char *binary_name, const int status)
{
	if (status == NO_SUCH_BINARY)
		ft_printf("No such binary: %s\n", binary_name);
	else if (status == NO_SUCH_ENV)
		ft_printf("No such environment variable exists\n");
	else if (status == SETENV_SYNTAX_ERROR)
		ft_printf("./Usage: setenv ['KEY=VALUE' or 'KEY = VALUE']\n");
	else if (status == UNSETENV_ARGS_ERROR)
		ft_printf("./Usage: unsetenv [KEY ...]\n");
	else if (status == TOO_MANY_ARGS)
		ft_printf("%s: too many arguments\n", binary_name);
	else if (status == PERMISIION_DENIED)
		ft_printf("%s: permission denied\n", binary_name);
	else if (status == NO_OLD_PWD_VAR)
		ft_printf("%s: env variable OLD_PWD does not exist", binary_name);
	else if (status == NO_SUCH_DIR)
		ft_printf("%s: no such directory exists", binary_name);
}
