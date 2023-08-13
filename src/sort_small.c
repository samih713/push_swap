/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:36 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 19:18:43 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max(t_stack *a)
{
	int		max;
	int		i;
	t_num	*temp;

	i = 0;
	temp = a->top;
	max = temp->num;
	while (i < a->size)
	{
		if (temp->num > max)
			max = temp->num;
		temp = temp->below;
		i++;
	}
	return (max);
}

void	sort_3(t_stack *a, int *max)
{
	*max = get_max(a);
	if (is_descending(a) && a->size == 3)
	{
		swap(a);
		rrot(a);
	}
	else if (a->top->num > a->top->below->num && a->bot->num == *max)
		swap(a);
	else if (a->top->num == *max && a->top->below->num < a->bot->num)
		rot(a);
	else if (a->bot->num > a->top->num && a->top->below->num == *max)
	{
		swap(a);
		rot(a);
	}
	else
		rrot(a);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	max;

	if (is_ascending(a))
		return ;
	if (a->size <= 3)
	{
		sort_3(a, &max);
		return ;
	}
	while (a->size > 3)
		push(a, b);
	sort_3(a, &max);
	while (b->size) {
		if (b->top->num < a->top->num)
			push(b, a);
		else if (b->top->num > max) {
			max = b->top->num;
			push(b, a);
			rot(a);
		}
		else
		{
			while (b->top->num > a->top->num)
				rot(a);
			push(b, a);
		}
		while (!is_ascending(a))
			rot(a);
	}
}
