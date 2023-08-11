/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:13:16 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/11 20:49:30y sabdelra         ###   ########.fr       */
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
	while (i < a->size - 1)
	{
		if (node->num > temp->num)
			node->rank++;
		temp = temp->below;
		i++;
	}
	rank(a, node->below, start);
}

void 	sort(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		max_bits;
	int		num;

	j = -1;
	max_bits = 0;
	rank(a, a->top, NULL); // ranks the nodes
	while (((a->size - 1) >> max_bits) != 0)
		max_bits++;
	while (++j < max_bits)
	{
		i = 0;
		while (i < a->size)
		{
			num = a->top->rank;
			if ((num >> j) & 1)
				rot(a);
			else
				push(a, b);
			i++;
		}
		while(b->size)
			push(b, a);
	}
}
