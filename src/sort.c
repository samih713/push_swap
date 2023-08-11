/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:46:45 by sabdelra          #+#    #+#             */
/*   Updated: 2023/07/27 20:29:06by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

enum number_of_rotations
{
	A,
	B,
	TOTAL
};

static void set_up(t_stack *a, t_stack *b)
{
	if (a->size < 3)
	{
		if (a->top->num > a->bot->num)
			swap(a);
		return ;
	}
	else if (a->size == 3)
	{
		sort_3(a, b);
		return ;
	}
	else
	{
		push(a, b);
		push(a, b);
		if (b->top->num < b->bot->num)
			swap(b);
		push(a, b);
		if (b->top->num < b->bot->num)
			rot(b);
		else if (b->top->num < b->top->below->num)
			swap(b);
	}
}

static bool fits(t_num *tempa, t_num *tempb, int *counter)
{
	if (tempa->num > tempb->num && tempa->num < tempb->above->num)
		return (true);
	else if (tempa->num > tempb->num && tempb->num > tempb->above->num) // tempb is the largest number in the stack
		return (true);
	else if (tempa->num < tempb->num && tempb->num < tempb->below->num) // tempb is the smallest number in the stack
	{
		(*counter)++;
		return (true);
	}
	return (false);
}

static void find_min_rotations(t_stack *a, t_stack *b, int *min)
{
	t_num	*temp[2];
	int		counter[2];

	counter[A] = 0;
	min[TOTAL] = 0;
	temp[A] = a->top;
	while (counter[A] < a->size)
	{
		counter[B] = 0;
		temp[B] = b->top;
		while (counter[B] < b->size && !fits(temp[A], temp[B], &counter[B]))
		{
			counter[B]++;
			temp[B] = temp[B]->below;
		}
		if (!min[TOTAL] || (min[TOTAL] > counter[A] + counter[B]))
		{
			min[A] = counter[A];
			min[B] = counter[B];
			min[TOTAL] = min[A] + min[B];
		}
		counter[A]++;
		temp[A] = temp[A]->below;
	}
}

void mechanicalTurk(t_stack *a, t_stack *b)
{
	int	min[3];

	set_up(a, b);
	while (a->size && !is_ascending(a))
	{
		find_min_rotations(a, b, min);
		while (min[A] && min[B])
		{
			rot_r(a, b);
			min[A]--;
			min[B]--;
		}
		while (min[A])
		{
			rot(a);
			min[A]--;
		}
		while (min[B])
		{
			rot(b);
			min[B]--;
		}
		push(a, b);
	}
	while (!is_descending(b))
		rot(b);
	while (b->size)
		push(b, a);
}
