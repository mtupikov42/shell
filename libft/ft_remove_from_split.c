#include "includes/libft.h"

char	**ft_remove_from_split(char **split, char *var)
{
	int		len;
	int		i;
	int		j;
	char	**new_split;

	i = 0;
	j = 0;
	len = ft_strsplit_count(split);
	new_split = (char **)ft_memalloc(sizeof(char *) * len);
	while (split[i])
	{
		if (ft_strncmp(var, split[i], ft_strlen(var)))
		{
			new_split[j] = split[i];
			++j;
		}
		else
		{
			free(split[i]);
		}
		++i;
	}
	return (new_split);
}