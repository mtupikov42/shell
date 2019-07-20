/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:19:20 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 12:40:31 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment/variables_expansion.h"
#include "environment/environment.h"
#include "utils/environment_utils.h"
#include "utils/shell_utils.h"
#include "libft.h"

static bool		after_home_is_valid(const char c)
{
	return (c == '/' || c == '\0' || ft_is_whitespace(c));
}

static bool		check_home(const char *line, const int i)
{
	return ((line[i] == HOME_SYM &&
			i == 0 && after_home_is_valid(line[i + 1])) || (i > 0 &&
			line[i] == HOME_SYM && ft_is_whitespace(line[i - 1]) &&
			after_home_is_valid(line[i + 1])));
}

char		*replace_home_variable(const char *line)
{
	char	*result;
	char	*var;
	char	*tmp;
	int		i;
	int		len;

	if (!line)
		return (NULL);
	var = get_environment(HOME_VAR);
	len = ft_strlen(var);
	i = 0;
	result = ft_strdup(line);
	while (result[i])
	{
		if (check_home(&result[i], i))
		{
			tmp = ft_replace_substring(result, "~", var);
			free(result);
			result = tmp;
			i += len - 1;
		}
		++i;
	}
	free(var);
	return (result);
}

void			expand_variables(char **line)
{
	char *tmp;

	tmp = replace_home_variable(*line);
	free(*line);
	*line = replace_environment_variables(tmp);
	free(tmp);
}