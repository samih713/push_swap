/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:47:59 by sabdelra          #+#    #+#             */
/*   Updated: 2023/05/29 21:33:49 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void split(t_stack *a, t_stack *b)
{
	int i;

	i = a->size;
	while (i > 0)
	{
		if (is_ascending(a)) break;
		do {
			 rot(a);
			 i--;
		} while (a->size && i && a->top->num > a->bot->num);
		do {
			push(a, b);
			i--;
		} while (a->size && b->top->num < a->top->num);
	}
}

void merge(t_stack *a, t_stack *b)
{
	int	i, counter;

	counter = 0;
	while (b->size)
	{
		//! if (is_descending(b)) break; "why does this result in an infinite loop it??"
		i = a->size;
		while (i > 0 && a->top->num < b->top->num)
		{
			rot(a);
			i--;
		}
		push(b,a);
		while (b->size && b->top->num > a->top->num)
		{
			push(b,a);
			counter++;
		}
		while (counter)
		{
			rot(a);
			counter--;
		}
	}
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	stack_init(&a, str(a));
	stack_init(&b, str(b));
	if (!argv[1] || !*(argv[1]))
		return 0;
	stack_fill(&a, argv, argc - 1);
	int i = 0;
	while(!is_ascending(&a) || i < 10)
	{
		split(&a, &b);
		merge(&a, &b);
		i++;
	}
	free_stack(&a);
	free_stack(&b);
}

