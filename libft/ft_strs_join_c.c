/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_join_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:21:22 by mtupikov          #+#    #+#             */
/*   Updated: 2019/07/18 22:07:20 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	j = -1;
	while (str2[++j])
		res[++i] = str2[j];
	return (res);
}
