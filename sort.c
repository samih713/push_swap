/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:27:27 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/05 05:05:13 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define PRINTOFF

// ! no use for now
t_scan	*scan(t_stack *a)
{
	t_scan	*scan;
	int		l;

	scan = malloc(sizeof(t_scan));
	a->cur = a->bot;
	scan->start = a->cur;
	scan->longest = 0;
	while(a->cur && a->cur->above)
	{
		l = 1;
		while(a->cur->above && a->cur->num > ((t_num *)(a->cur->above))->num)
		{
			printf("here\n");
			l++;
			a->cur = a->cur->above;
		}
		if (l > scan->longest)
		{
			scan->longest = l;
			scan->start = a->cur;
		}
		a->cur = a->cur->above;
	}
	return (scan);
}
// !

// * split stacks into
void	split_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	size_a; // size of a at start

	i = 0;
	size_a = a->size;
	if (check_ascending(a))
		return ;
	while (a->bot->num < a->top->num) {
		rrot(a, 'a');
		#ifdef PRINTON
		print_stack(a, 'a');
		print_stack(b, 'b');
		#endif
	}
	while (i < size_a)
	{
		while (a->top->num < ((t_num *)(a->top->below))->num)
		{
			rot(a, 'a');
			i++;
		}
		print_rstack(b, 'b');

		i++;
	}
}

// * check functions check from top to bottom
int		check_ascending(t_stack *stack)
{
	int	i;

	i = 0;
	stack->cur = stack->top;
	while (i < stack->size && stack->cur->below)
	{
		if (stack->cur->num > ((t_num *)(stack->cur->below))->num)
			return (0);
		stack->cur = stack->cur->below;
		i++;
	}
	return (1);
}

int		check_descending(t_stack *stack)
{
	int	i;

	i = 0;
	stack->cur = stack->bot;
	while (i < stack->size && stack->cur->above)
	{
		if (stack->cur->num > ((t_num *)(stack->cur->above))->num)
			return (0);
		stack->cur = stack->cur->above;
		i++;
	}
	return (1);
}
// * check functions -------------------------

// * go through A once, place a run at the bottom of A (ra till run is done)
// * then, place 2nd run at the bottom of b (pb -> rb)
