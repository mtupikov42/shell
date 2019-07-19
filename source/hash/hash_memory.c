/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:23:44 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/19 17:24:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hash_table.h"
#include "libft.h"

t_hashed_item		*ht_alloc_hashed_item_m(char *key, char *value)
{
	t_hashed_item	*item;

	if (!(item = (t_hashed_item *)ft_memalloc(sizeof(t_hashed_item))))
		return (NULL);
	item->key = key;
	item->value = value;
	return (item);
}

t_hashed_item		*ht_alloc_hashed_item(const char *key, const char *value)
{
	t_hashed_item	*item;
	char 			*c_key;
	char			*c_value;

	c_key = ft_strdup(key);
	c_value = ft_strdup(value);
	item = ht_alloc_hashed_item_m(c_key, c_value);
	if (!item)
	{
		free(c_key);
		free(c_value);
	}
	return (item);
}

t_hash_table		*ht_alloc_hash_table(const int capacity)
{
	t_hash_table	*table;

	if (!(table = (t_hash_table *)ft_memalloc(sizeof(t_hash_table))))
		return (NULL);
	table->capacity = capacity;
	table->size = 0;
	table->array = (t_hashed_item **)ft_memalloc(sizeof(t_hashed_item *) *
		(capacity + 1));
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	return (table);
}

void				delete_hashed_item(t_hashed_item *item)
{
	if (item) {
		safe_free(item->key);
		safe_free(item->value);
		free(item);
	}
}

void				delete_hash_table(t_hash_table *table)
{
	int	i;

	if (table)
	{
		if (table->array)
		{
			i = 0;
			while (table->array[i])
			{
				delete_hashed_item(table->array[i]);
				++i;
			}
			free(table->array);
		}
		free(table);
	}
}
