/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:46:43 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:37:57 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/cd_cmd.h"
#include "utils/shell_utils.h"
#include "environment/environment.h"
#include <unistd.h>
#include "libft.h"

static int	access_path(const char *dir)
{
	int	status;

	status = NO_SUCH_DIR;
	if (dir && access(dir, F_OK) == 0)
	{
		if (access(dir, X_OK) == 0)
			return (chdir(dir));
		return (PERMISIION_DENIED);
	}
	return (status);
}

int			execute_cd(const char *dir, const char *old_pwd)
{
	int		status;
	char	*home_path;

	status = SUCCESS;
	if (!dir)
	{
		home_path = get_environment(HOME_VAR);
		if (home_path)
		{
			status = access_path(home_path);
			free(home_path);
		}
	}
	else if (ft_strcmp(dir, CD_PREV_PATH) == 0)
	{
		if (!old_pwd)
			return (NO_OLD_PWD_VAR);
		status = access_path(old_pwd);
	}
	else
		status = access_path(dir);
	return (status);
}
