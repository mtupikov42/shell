/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:46:43 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/19 12:37:22 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins/cd_cmd.h"
#include <unistd.h>

static int	access_path(const char *dir)
{
	int	status;

	status = CD_NO_SUCH_DIR;
	if (dir && access(dir, F_OK) == 0)
	{
		if (access(dir, X_OK) == 0)
			return (chdir(dir));
		return (CD_PERMISIION_DENIED);
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
			return (CD_NO_OLD_PWD);
		status = access_path(old_pwd);
	}
	else
		status = access_path(dir);
	return (status);
}
