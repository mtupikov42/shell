#include "includes/libft.h"

char	*ft_split_join_delimiter(const char **split, const char *delimiter)
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	len = 0;
	while (split[++i])
		len += ft_strlen(split[i]);
	len += ft_strsplit_count(split);
	str = (char *)ft_memalloc(sizeof(char) * len);
	i = -1;
	while (split[++i])
	{
		if (ft_strlen(split[i]) == 0)
			continue;
		ft_strlcat(str, split[i], len);
		if (ft_strlcat(str, delimiter, len) > len)
			break;
	}
	return (str);
}

char	*ft_split_join(const char **split)
{
	return ft_split_join_delimiter(split, "");
}