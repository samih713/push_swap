/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:31:52 by sabdelra          #+#    #+#             */
/*   Updated: 2023/05/01 16:41:19 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	bubble(t_stack *a, t_stack *b);
static bool compare_top(t_stack *stack);
static bool compare_tbot(t_stack *stack);

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	stack_init(&a, str(a));
	stack_init(&b, str(b));
	if (!argv[1] || !*(argv[1]))
		return 0;
	stack_fill(&a, argv, argc - 1);
	bubble(&a, &b);
	free_stack(&a);
	free_stack(&b);
}

static int	bubble(t_stack *a, t_stack *b)
{
	int counter = 0;
	t_num *temp;

	while (!is_ascending(a)){
		while (a->size) {
			for(temp = a->top;temp->below && temp->num < temp->below->num; temp = temp->below);
			if (a->size && temp->num == a->bot->num) break;
			while (a->size > 2 && a->top->num < a->top->below->num) {
				if (!compare_tbot(a)) rrot(a);
				push(a, b);
			}
			if (compare_top(a) && compare_tbot(a)) {
				push(a, b);
			}
			else if (compare_top(a)) {
				rrot(a);
				push(a, b);
			}
			else if (compare_tbot(a)) {
				if (compare_top(b)) swap_s(a, b);
				else swap(a);
				push(a, b);
			}
			else {
				if (compare_top(b)) swap_s(a, b);
				else swap(a);
				if (compare_tbot(a)) push(a, b);
				else {
					rrot(a);
					push(a, b);
				}
			}
		}
		while (b->size) {
			for(temp = b->top; temp->below && temp->num > temp->below->num; temp = temp->below);
			if (b->size && temp->num == b->bot->num) break;
			while (b->size > 2 && b->top->num > b->top->below->num) {
				push(b, a);
			}
			if (!compare_top(b) && !compare_tbot(b)) {
				push(b, a);
			}
			else if (!compare_top(b)) {
				rrot(b);
				push(b, a);
			}
			else if (!compare_tbot(b)) {
				if (!compare_top(a)) swap_s(a, b);
				else swap(b);
				push(b, a);
			}
			else {
				if (!compare_top(a)) swap_s(a, b);
				else swap(b);
				if (!compare_tbot(b)) push(b, a);
				else {
					rrot(b);
					push(b, a);
				}
			}
		}
	}
	while (b->size) push(b,a);
	return counter;
}

// top < bot
static bool compare_tbot(t_stack *stack)
{
	if (stack->size < 2) return false;
	return (stack->top->num < stack->bot->num); // top < bot
}

// top < 2nd
static bool compare_top(t_stack *stack)
{
	if (stack->size < 2) return false;
	return (stack->top->num < stack->top->below->num);
}

