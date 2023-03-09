/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:38:20 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/09 04:25:11 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_empty_stack(t_stack *stack)
{
	stack->cur = NULL;
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

t_num	*create_node(int num)
{
	t_num	*node;

	node = malloc(sizeof(t_num));
	mem_check(node);
	node->num = num;
	node->below = NULL;
	node->above = NULL;
	return (node);
}

void	insert_node(t_num *node, t_num *above, t_num *below)
{
	node->above = above;
	node->below = below;
	if (below)
		below->above = node;
}

void	fill_stack(t_stack *stack, char **numbers, int count)
{
	int		i;
	t_num	*node;
	t_hash	*table;

	i = 0;
	table = create_hash_table(count);
	stack->size = count;
	while (i < count) {
		node = create_node(ft_atoi(numbers[count - i]));
		if (i == 0)
			stack->bot = node;
		stack->top = node;
		insert_node(node, NULL, stack->cur);
		stack->cur = node;
		check_duplicates(stack, node, table);
		i++;
	}
	// * circular
	stack->top->above = stack->bot;
	stack->bot->below = stack->top;
	if (table)
		free_table(table);
}

// TODO replace printf
void	print_stack(t_stack *stack, char stack_name)
{
	int	i;

	i = 0;
	stack->cur = stack->top;
	while (i < stack->size)
	{
		printf("%7d\n", stack->cur->num);
		stack->cur = stack->cur->below;
		i++;
	}
	printf("--- stack (%c) ---\n", stack_name);
}

// TODO replace printf
void	print_rstack(t_stack *stack, char stack_name)
{
	int	i;

	i = 0;
	stack->cur = stack->bot;
	while (i < stack->size)
	{
		printf("%7d\n", stack->cur->num);
		stack->cur = stack->cur->above;
		i++;
	}
	printf("--- stack (%c) ---\n", stack_name);
}

void	free_stack(t_stack *stack)
{
	t_num	*above;
	int		i;

	stack->cur = stack->bot;
	i = 0;
	while (i < stack->size)
	{
		// * this is needed, in case of duplicate, quits before the top->above is set
		if (stack->cur)
			above = stack->cur->above;
		free(stack->cur);
		stack->cur = above;
		i++;
	}
	free(stack);
}

// * atoi handles the INT_MAX and INT_MIN
int		ft_atoi(const char *num)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (num[i])
	{
		if ((num[i] > '9' || num[i] < '0') && num[i] != '-')
			error_msg();
		i++;
	}
	i = 0;
	if (num[i] == '-')
	{
		sign *= -1;
		i++;
		if (!(num[i] >= '0' && num[i] <= '9'))
			error_msg();
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		result = (num[i] - '0') + (result * 10);
		if (result > INT_MAX || (result > (INT_MAX - 1) && sign == -1))
			error_msg();
		i++;
	}
	return (result * sign);
}

t_hash	*create_hash_table(int size)
{
	t_hash	*hash_table;
	int		i;

	i = 0;
	hash_table = malloc(sizeof(t_hash));
	mem_check(hash_table);
	hash_table->size = size;
	hash_table->entries = malloc(sizeof(t_entry *) * size);
	mem_check(hash_table->entries);
	while (i < size)
	{
		hash_table->entries[i] = NULL;
		i++;
	}
	return (hash_table);
}

// TODO use smaller tables, using table size might lead to alot of empty spots
unsigned int	hash(int num, int table_size)
{
	return (abs(num) % table_size);
}

// TODO remove the else if
void	check_duplicates(t_stack *stack, t_num *node, t_hash *table)
{
	unsigned int	hash_value;
	t_entry			*c_entry;

	hash_value = hash(node->num, table->size);
	if (!table->entries[hash_value])
	{
		table->entries[hash_value] = malloc(sizeof(t_entry));
		mem_check(table->entries[hash_value]);
		table->entries[hash_value]->value = node->num;
		table->entries[hash_value]->next = NULL;
	}
	else
	{
		c_entry = table->entries[hash_value];
		while (c_entry)
		{
			if (c_entry->value == node->num)
			{
				printf("%d is a duplicate\n", node->num);
				free_stack(stack);
				free_table(table);
				error_msg();
			}
			else if (c_entry->next == NULL)
			{
				c_entry->next = malloc(sizeof(t_entry));
				mem_check(c_entry->next);
				c_entry = c_entry->next;
				c_entry->next = NULL;
				c_entry->value = node->num;
			}
			c_entry = c_entry->next;
		}
	}
}

void	free_table(t_hash *table)
{
	unsigned int	index;
	t_entry			*next;

	index = 0;
	while (index < table->size)
	{
		while (table->entries[index])
		{
			next = table->entries[index]->next;
			free(table->entries[index]);
			table->entries[index] = next;
		}
		index++;
	}
	free(table->entries);
	free(table);
}

int		check_sort(t_stack *stack)
{
	int comparison;

	stack->cur = stack->top;
	while (stack->cur->below)
	{
		comparison = stack->cur->num;
		stack->cur = stack->cur->below;
		comparison -= stack->cur->num;
		if (comparison > 0)
			return (0);
	}
	return (1);
}
