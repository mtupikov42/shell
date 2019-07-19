/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_hash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:09:39 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/19 16:11:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/string_to_hash.h"

unsigned long	string_to_hash(const char *str)
{
	unsigned long	hash;
	char			c;

	hash = 0;
	while (c = *str++)
		hash = c + (hash << 6) + (hash << 16) - hash;
	return (hash);
}
