/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:53:09 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 17:58:49 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/errors.h"
#include "utils/shell_utils.h"
#include "libft.h"

void	print_error(const char *binary_name, const int status)
{
	if (status == NO_SUCH_BINARY)
		ft_printf("minishell: no such binary: %s\n", binary_name);
	else if (status == NO_SUCH_ENV)
		ft_printf("minishell: no such environment variable exists\n");
	else if (status == SETENV_SYNTAX_ERROR)
		ft_printf("./Usage: setenv ['KEY=VALUE' or 'KEY = VALUE']\n");
	else if (status == UNSETENV_ARGS_ERROR)
		ft_printf("./Usage: unsetenv [KEY ...]\n");
	else if (status == TOO_MANY_ARGS)
		ft_printf("minishell: %s: too many arguments\n", binary_name);
	else if (status == PERMISIION_DENIED)
		ft_printf("minishell: %s: permission denied\n", binary_name);
	else if (status == NO_OLD_PWD_VAR)
		ft_printf("minishell: %s: env variable OLD_PWD does not exist\n",
			binary_name);
	else if (status == NO_SUCH_DIR)
		ft_printf("minishell: %s: no such directory exists\n", binary_name);
	else if (status == NO_PWD_VAR)
		ft_printf("minishell: %s: env variable PWD does not exist\n",
			binary_name);
	else if (status == NO_PATH_VAR)
		ft_printf("minishell: %s: env variable PATH does not exist\n",
			binary_name);
}
