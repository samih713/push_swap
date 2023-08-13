/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:01:05 by eva-001           #+#    #+#             */
/*   Updated: 2023/08/13 22:16:00 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DUPLICATE 1

//?		Helper functions
static void			htable_init(int size, t_hash *table);
static t_num		*init_node(void);
static int			quit(t_hash *table);

/*
Fills the stack with numbers from an array of strings, the numbers are stored
as a doubly linked list. bot->below and top->above are NULL;

First argument is the top of the stack, stack starts at bot ---> above
Duplicate checking is done using a hast_table implementation
atoi handles multiple invalid argument cases, and exits cleanly
 */
int	stack_fill(t_stack *s, char **n, int c)
{
	t_num	*node;
	t_hash	table;
	int		err_atoi;

	htable_init(c, &table);
	while (s->size < c)
	{
		node = init_node();
		if (!s->size)
			s->bot = node;
		else
		{
			s->top->above = node;
			node->below = s->top;
			node->above = s->bot;
			s->bot->below = node;
		}
		s->top = node;
		node->num = (_ft_atoi(n[c - s->size - 1], &err_atoi));
		node->str = n[c - s->size - 1];
		s->size++;
		if (check_duplicates(node, &table) || err_atoi)
			return (quit(&table) && 0);
	}
	return (quit(&table));
}

/*
Frees the hash table, and checks for already sorted before returning
*/
static int	quit(t_hash *table)
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
