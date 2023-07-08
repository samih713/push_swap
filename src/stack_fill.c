/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:01:05 by eva-001           #+#    #+#             */
/*   Updated: 2023/07/08 01:10:20 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DUPLICATE 1

//?		Helper functions
static void			htable_init(int size, t_hash *table);
static void			check_duplicates(t_stack *stack,
						t_num *node, t_hash *table);
static t_num		*init_node(void);
static void			quit(t_hash *table, t_stack *stack, int dup);

/*
Fills the stack with numbers from an array of strings, the numbers are stored
as a doubly linked list. bot->below and top->above are NULL;

First argument is the top of the stack, stack starts at bot ---> above
Duplicate checking is done using a hast_table implementation
atoi handles multiple invalid argument cases, and exits cleanly
 */
void	stack_fill(t_stack *stack, char **n_list, int count)
{
	t_num	*node;
	t_hash	table;

	htable_init(count, &table);
	while (stack->size < count)
	{
		node = init_node();
		if (!stack->size)
			stack->bot = node;
		else
		{
			stack->top->above = node;
			node->below = stack->top;
			node->above = stack->bot;
			stack->bot->below = node;
		}
		stack->top = node;
		node->num = (_ft_atoi(n_list[count - stack->size], stack, &table));
		node->str = n_list[count - stack->size];
		stack->size++;
		check_duplicates(stack, node, &table);
	}
	quit(&table, stack, 0);
}

/*
Frees the hash table, and checks for already sorted before returning
*/
static void	quit(t_hash *table, t_stack *stack, int dup)
{
	if (table)
		free_table(table);
	if (is_ascending(stack) || dup)
	{
		free_stack(stack);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

/*
Creates a hash table with size entries
*/
static void	htable_init(int size, t_hash *table)
{
	unsigned int		i;

	i = 0;
	table->entries = malloc(sizeof(t_entry *) * size);
	if (table->entries)
	{
		table->size = size;
		while (table->entries && i < table->size)
		{
			table->entries[i] = NULL;
			i++;
		}
	}
	return ;
}

/*
checks for duplicates as the arguments are being read,
checks their hash table entry for a reading
handles collisions by a single linked list of c_entry's
*/
static void	check_duplicates(t_stack *stack, t_num *node, t_hash *table)
{
	unsigned int	hash_value;
	t_entry			*c_entry;

	hash_value = abs(node->num) % table->size;
	if (!table->entries[hash_value])
	{
		table->entries[hash_value] = mem_check(malloc(sizeof(t_entry)));
		table->entries[hash_value]->value = node->num;
		table->entries[hash_value]->next = NULL;
	}
	else
	{
		c_entry = table->entries[hash_value];
		while (c_entry)
		{
			if (c_entry->value == node->num)
				quit(table, stack, DUPLICATE);
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
}

/*
returns a t_num *node, sets above and below to NULL
doesn't set value for node->num
*/
static t_num	*init_node(void)
{
	t_num	*node;

	node = mem_check(malloc(sizeof(t_num)));
	node->above = NULL;
	node->below = NULL;
	return (node);
}
