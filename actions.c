/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:53:41 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/10 04:42:45 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char name)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->num;
	stack->top->num = ((t_num *)(stack->top->below))->num;
	((t_num *)(stack->top->below))->num = temp;
	write(1, "s", 1);
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
	temp = stack->top;
	stack->top = temp->below;
	stack->bot = temp;
	write(1, "r", 1);
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

	if (stack->size < 2)
		return ;
	temp = stack->bot;
	stack->bot = temp->above;
	stack->top = temp;
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

	if (a->size < 1)
		return ;
	a->bot->below = a->top->below;
	((t_num *)(a->top->below))->above = a->bot;
	temp = a->top;
	a->top = a->top->below;
	if (b->size)
	{
		b->top->above = temp;
		temp->below = b->top;
		temp->above = b->bot;
		b->bot->below = temp;
		b->top = temp;
	}
	else
	{
		b->top = temp;
		b->bot = temp;
		temp->above = NULL;
		temp->below = NULL;
	}
	a->size--;
	b->size++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_num	*temp;

	if (b->size < 1)
		return ;
	b->bot->below = b->top->below;
	((t_num *)(b->top->below))->above = b->bot;
	temp = b->top;
	b->top = b->top->below;
	if (a->size)
	{
		a->top->above = temp;
		temp->below = a->top;
		temp->above = a->bot;
		a->bot->below = temp;
		a->top = temp;
	}
	else
	{
		a->top = temp;
		a->bot = temp;
		temp->above = NULL;
		temp->below = NULL;
	}
	b->size--;
	a->size++;
	write(1, "pa\n", 3);
}

