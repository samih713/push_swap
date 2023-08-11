/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:01:05 by eva-001           #+#    #+#             */
/*   Updated: 2023/08/11 20:00:18 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DUPLICATE 1

//?		Helper functions
static void			htable_init(int size, t_hash *table);
static int			check_duplicates(t_stack *stack,
						t_num *node, t_hash *table);
static t_num		*init_node(void);
static int			quit(t_hash *table, t_stack *stack);

/*
Fills the stack with numbers from an array of strings, the numbers are stored
as a doubly linked list. bot->below and top->above are NULL;

First argument is the top of the stack, stack starts at bot ---> above
Duplicate checking is done using a hast_table implementation
atoi handles multiple invalid argument cases, and exits cleanly
 */
int	stack_fill(t_stack *stack, char **numbers, int count)
{
	t_num	*node;
	t_hash	table;
	int		err_atoi;

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
		node->num = (_ft_atoi(numbers[count - stack->size - 1], stack, &table, &err_atoi));
		node->str = numbers[count - stack->size - 1];
		stack->size++;
		if(check_duplicates(stack, node, &table) || err_atoi)
			return(quit(&table, stack) && 0);
	}
	return (quit(&table, stack));
}

/*
Frees the hash table, and checks for already sorted before returning
*/
static int	quit(t_hash *table, t_stack *stack)
{
	if (table)
		free_table(table);
	return (1);
}

/*
Creates a hash table with size entries
*/
static void	htable_init(int size, t_hash *table)
{
	unsigned int		i;

	i = 0;
	table->entries = mem_check(malloc(sizeof(t_entry *) * size));
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
static int	check_duplicates(t_stack *stack, t_num *node, t_hash *table)
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

/*
returns a t_num *node, sets above and below to NULL
doesn't set value for node->num
*/
static t_num	*init_node(void)
{
	t_num	*node;

	node = mem_check(malloc(sizeof(t_num)));
	node->rank = 0;
	node->str = 0;
	node->above = NULL;
	node->below = NULL;
	return (node);
}
