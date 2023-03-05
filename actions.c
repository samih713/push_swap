/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:53:41 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/05 03:39:58 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO operation on an empty stack
void	swap(t_stack *stack, char name)
{
	t_num	*temp;

	temp = stack->top;
	stack->top = stack->top->below;
	stack->top->above = NULL;
	temp->below = stack->top->below;
	stack->top->below = temp;
	temp->above = stack->top;
	write(1, "s", 1);
	// TODO add new line
	if (name)
	{
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	swap_s(t_stack *a, t_stack *b)
{
	swap(a, 0);
	swap(b, 0);
	write(1, "\n", 1);
}

void	rot(t_stack *stack, char name)
{
	t_num	*temp;

	if (stack->size < 2)
		return ;
	stack->top->above = stack->bot;
	stack->bot->below = stack->top;
	temp = stack->top->below;
	stack->top->below = NULL;
	stack->bot = stack->bot->below;
	stack->top = temp;
	temp->above = NULL;
	write(1, "r", 1);
	// TODO add new line
	if (name)
	{
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	rot_r(t_stack *a, t_stack *b)
{
	rot(a, 0);
	rot(b, 0);
	write(1, "\n", 1);
}

void	rrot(t_stack *stack, char name)
{
	t_num	*temp;

	if (stack->top == stack->bot)
		return ;
	temp = stack->bot->above;
	stack->bot->below = stack->top;
	stack->top->above = stack->bot;
	stack->bot->above = NULL;
	stack->top = stack->bot;
	stack->bot = temp;
	stack->bot->below = NULL;
	write(1, "rr", 2);
	if (name)
	{
		write(1, &name, 1);
		write(1, "\n", 1);
	}
}

void	rrot_r(t_stack *a, t_stack *b)
{
	rrot(a, 0);
	rrot(b, 0);
	write(1, "r", 1);
}

// TODO revise the logic here
void	pb(t_stack *a, t_stack *b)
{
	t_num	*temp;

	temp = a->top->below;
	if (temp) // ! in case a had one element
		temp->above = NULL;
	if (b->top)
	{
		a->top->below = b->top;
		b->top->above = a->top;
		b->top = a->top;
		a->top = temp;
	}
	else
	{
		b->top = a->top;
		b->bot = a->top;
		b->top->below = NULL;
		b->top->above = NULL;
		a->top = temp;
	}
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_num	*temp;

	temp = b->top->below;
	if (temp) // ! in case a had one element
		temp->above = NULL;
	if (a->top)
	{
		b->top->below = a->top;
		a->top->above = b->top;
		a->top = b->top;
		b->top = temp;
	}
	else
	{
		a->top = b->top;
		a->bot = b->top;
		a->top->below = NULL;
		a->top->above = NULL;
		b->top = temp;
	}
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

