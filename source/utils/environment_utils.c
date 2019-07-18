#include "utils/environment_utils.h"

#include "libft.h"

bool	variable_is_valid(const char *variable)
{
	int i;

	if (!variable)
	{
		return (false);
	}

	i = 0;
	while (variable[i])
	{
		if (!(ft_isalnum(var[i]) || var[i] == '_' || var[i] == '$'))
		{
			return (false);
		}
		++i;
	}
	return (true);
}