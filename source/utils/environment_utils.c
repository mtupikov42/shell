/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:23:00 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 19:47:46 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/environment_utils.h"
#include "environment/environment.h"
#include "libft.h"
#include <stdbool.h>

static bool	is_var_symbol(const char c)
{
	return (ft_isalnum(c) || c == '_' || c == '$');
}

static int	var_length(const char *line)
{
	int len;

	len = 0;
	while (line[len] && (is_var_symbol(line[len])))
	{
		++len;
	}
	return (len);
}

static char	*grab_variable(const char *line, const int len)
{
	char	*var;
	int		i;

	if (len == 0)
	{
		return (NULL);
	}
	var = (char *)ft_memalloc(sizeof(char) * (len));
	i = 0;
	while (i < len)
	{
		var[i] = line[i];
		++i;
	}
	return (var);
}

bool		variable_is_valid(const char *var)
{
	int i;

	if (!var)
	{
		return (false);
	}
	i = 0;
	while (var[i])
	{
		if (!(is_var_symbol(var[i])))
		{
			return (false);
		}
		++i;
	}
	return (true);
}

char		*replace_environment_variables(char *line)
{
	int		i;
	int		len;
	char	*res;
	char	*key;
	char	*value;

	i = -1;
	if ((res = ft_strdup(line)))
		while (res[++i])
			if (res[i] == '$')
			{
				len = var_length(&res[i]);
				if (!(key = grab_variable(&res[i], len)))
					continue;
				if (!(value = get_environment(key + 1)))
					value = ft_strnew(0);
				line = ft_replace_substring(res, key, value);
				len = ft_strlen(value);
				free(res);
				free(key);
				free(value);
				res = line;
				i += len - 1;
			}
	return (res);
}
