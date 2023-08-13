/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:03:44 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 22:15:33 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_entry	*place_node(int value)
{
	t_entry	*node;

	node = mem_check(malloc(sizeof(t_entry)));
	node->value = value;
	node->next = NULL;
	return (node);
}

/*
checks for duplicates as the arguments are being read,
checks their hash table entry for a reading
handles collisions by a single linked list of c_entry's
*/
int	check_duplicates(t_num *node, t_hash *table)
{
	unsigned int	hash_value;
	t_entry			*c_entry;

	hash_value = abs(node->num) % table->size;
	if (!table->entries[hash_value])
		table->entries[hash_value] = place_node(node->num);
	else
	{
		c_entry = table->entries[hash_value];
		while (c_entry)
		{
			if (c_entry->value == node->num)
				return (1);
			else if (c_entry->next == NULL)
			{
				c_entry->next = mem_check(malloc(sizeof(t_entry)));
				c_entry = c_entry->next;
				c_entry->next = NULL;
				c_entry->value = node->num;
			}
			c_entry = c_entry->next;
		}
	}
	return (0);
}
