#include "includes/libft.h"

char	*ft_strs_join_c(char *str1, char *str2, char c)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(str1) + ft_strlen(str2) + 2;
	if (!(res = (char *)ft_memalloc(sizeof(char) * len)))
	{
		return (NULL);
	}
	i = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		++i;
	}
	res[i] = c;
	j = 0;
	while (str2[i])
	{
		res[i] = str2[j];
		++j;
		++i;
	}
	return (res);
}