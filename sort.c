/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:27:27 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/06 05:14:50 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		split_stack(t_stack *a, t_stack *b);
static void		merge_b(t_stack *a, t_stack *b);
static void		merge_a(t_stack *a, t_stack *b);
static int		check_ascending(t_stack *stack);
static int		check_descending(t_stack *stack);

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

// * sort
void	sort(t_stack *a, t_stack *b)
{
	printf("original\n\n");
	split_stack(a, b);
	print_stack(a, 'a');
	print_stack(b, 'b');
	printf("after split\n\n");
	merge_b(a, b);
	merge_a(a, b);
	check_descending(a);
}

// * split stacks into
static void	split_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	size_a; // size of a at start

	i = 0;
	size_a = a->size;
	if (check_ascending(a))
		return ;
	while (a->bot->num < a->top->num) {
		rrot(a, 'a');
	}
	while (i < size_a) {
		do
		{
			rot(a, 'a');
			i++;
		} while (a->top->num > ((t_num *)(a->bot))->num && i < size_a);
		do {
			pb(a, b);
			rot(b,'b');
			i++;
		} while (a->top->num < ((t_num *)(a->top->below))->num && i < size_a);
		i++;
	}
}

// * merge functions
static void	merge_b(t_stack *a, t_stack *b)
{
	if (a->top->num < b->top->num)
	{
		pb(a, b);
		rot(b, 'b');
		while (a->top->num < b->top->num)
		{
			pb(a, b);
			rot(b, 'b');
		}
		while (b->bot < a->top)
		{
			pb(a, b);
			rot(b, 'b');
		}
	}

}

static void	merge_a(t_stack *a, t_stack *b)
{
	if (b->top->num < a->top->num)
	{
		pa(a, b);
		rot(a, 'a');
		while (b->top->num < a->top->num)
		{
			pa(a, b);
			rot(a, 'a');
		}
		while (a->bot < b->top)
		{
			pa(a, b);
			rot(a, 'a');
		}
	}

}

// * check functions check from top to bottom
static int		check_ascending(t_stack *stack)
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

static int		check_descending(t_stack *stack)
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












/* if top of A < top of B:
    pb
rb
while bottom of B <= top of B:
    if top of A < top of B:
        pb
    rb
while bottom of B <= top of A:
    pb
    rb */
