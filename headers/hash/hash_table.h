/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <mtupikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:59:13 by anonymous         #+#    #+#             */
/*   Updated: 2019/07/20 20:26:18 by mtupikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

/*
** Hash Table structure
*/

typedef struct		s_hashed_item
{
	char			*key;
	char			*value;
}					t_hashed_item;

typedef struct		s_hash_table
{
	int				capacity;
	int				size;
	t_hashed_item	**array;
}					t_hash_table;

/*
** Hash Table memory functions
*/

t_hashed_item		*ht_alloc_hashed_item_m(char *key, char *value);
t_hashed_item		*ht_alloc_hashed_item(const char *key, const char *value);
t_hash_table		*ht_alloc_hash_table(const int capacity);
void				delete_hashed_item(t_hashed_item *item);
void				delete_hash_table(t_hash_table *table);

/*
** Hash Table items handling functions
*/

void				ht_insert_m(t_hash_table *table, char *key, char *value);
void				ht_insert(t_hash_table *table, const char *key,
					const char *value);
void				ht_remove(t_hash_table *table, const char *key);
char				*ht_get_value(t_hash_table *table, const char *key);

#endif
