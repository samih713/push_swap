/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:18:52 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/12 00:25:58 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rank(t_stack *a, t_num *node, t_num *start)
{
	int		i;
	t_num	*temp;

	if (!start)
		start = node;
	else if (node == start)
		return ;
	i = 0;
	temp = a->top;
	while (i < a->size)
	{
		if (node->num > temp->num)
			node->rank++;
		temp = temp->below;
		i++;
	}
	rank(a, node->below, start);
}

void	sort(t_stack *a, t_stack *b)
{
	int		counter[2];
	int		max_bits;
	int		num;
	int		size;

	counter[J] = -1;
	max_bits = 0;
	rank(a, a->top, NULL);
	size = a->size;
	while (((size - 1) >> max_bits))
		max_bits++;
	while (++counter[J] < max_bits)
	{
		counter[I] = -1;
		while (++counter[I] < size)
		{
			num = a->top->rank;
			if ((num >> counter[J]) & 1)
				rot(a);
			else
				push(a, b);
		}
		while (b->size)
			push(b, a);
	}
}
