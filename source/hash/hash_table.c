/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:07:39 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 20:26:44 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash/hash_table.h"
#include "hash/string_to_hash.h"
#include "libft.h"

void				ht_insert_m(t_hash_table *table, char *key, char *value)
{
	t_hashed_item	*item;
	unsigned long	hash_i;

	item = ht_alloc_hashed_item_m(key, value);
	hash_i = string_to_hash((const char *)key) % table->capacity;
	if (table->array[hash_i])
		delete_hashed_item(table->array[hash_i]);
	table->array[hash_i] = item;
	table->size++;
}

void				ht_insert(t_hash_table *table, const char *key,
					const char *value)
{
	t_hashed_item	*item;
	unsigned long	hash_i;

	item = ht_alloc_hashed_item(key, value);
	hash_i = string_to_hash(key) % table->capacity;
	if (table->array[hash_i])
		delete_hashed_item(table->array[hash_i]);
	table->array[hash_i] = item;
	table->size++;
}

void				ht_remove(t_hash_table *table, const char *key)
{
	unsigned long	index;
	t_hashed_item	*item;

	index = string_to_hash(key) % table->capacity;
	item = table->array[index];
	delete_hashed_item(table->array[index]);
}

char				*ht_get_value(t_hash_table *table, const char *key)
{
	unsigned long	index;
	t_hashed_item	*item;

	index = string_to_hash(key) % table->capacity;
	item = table->array[index];
	if (ft_strcmp(item->key, key) == 0)
		return (item->value);
	return (NULL);
}
