/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:29:02 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/20 12:31:52 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, const unsigned int start, const size_t len)
{
	unsigned int	i;
	char			*ret;

	if (s)
	{
		i = 0;
		if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		if (start >= ft_strlen(s) || ft_strlen(s) - start < len)
			return (NULL);
		while (i < len)
		{
			ret[i] = s[start + i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
