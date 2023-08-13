/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:36 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 21:56:46 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (is_ascending(a))
		return ;
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

static int	find_min(t_stack *a)
{
	int		min;
	int		i;
	t_num	*temp;

	i = 0;
	temp = a->top;
	min = temp->num;
	while (i < a->size)
	{
		temp = temp->below;
		if (temp->num < min)
			min = temp->num;
		i++;
	}
	return (min);
}

static void	push_min(t_stack *a, t_stack *b)
{
	int		min;
	int		r;

	while (a->size > 3)
	{
		r = 0;
		min = find_min(a);
		if (a->bot->num == min)
			rrot(a);
		while (a->top->num != min)
			rot(a);
		push(a, b);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	max;

	if (is_ascending(a))
		return ;
	if (a->size == 3)
	{
		sort_3(a, &max);
		return ;
	}
	push_min(a, b);
	sort_3(a, &max);
	while (b->size)
		push(b, a);
}
