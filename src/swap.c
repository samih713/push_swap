/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:32:11 by eva-001           #+#    #+#             */
/*   Updated: 2023/06/19 18:40:06 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//?		Helper functions
static void	_swap(t_stack *stack, bool ss);

//?		swap
/*
Calls _swap with ss set to 0 to indicate that move names
are to be printed
*/
void	swap(t_stack *stack)
{
	_swap(stack, 0);
}

/*
Performs a swap on both stacks, does nothing if any of the stacks is
empty
ss set to 1
*/
void	swap_s(t_stack *a, t_stack *b)
{
	if (!a->size || !b->size)
		return ;
	_swap(a, 1);
	_swap(b, 1);
	putstr("ss");
	putstr("\n");
}

//?		Internal function
/*
Take a single stack as an argument and performs a swap operation
on it, swapping the top 2 elements.
If the stack has fewer than 2 elements it does nothing.
The ss parameter indicates whether the swap operation is
performed on both stacks or not, to determine whether the move
name needs to be printed.
 */
static void	_swap(t_stack *stack, bool ss)
{
	t_num	temp;

	if (stack->size < 2)
		return ;
	temp.num = stack->top->num;
	temp.str = stack->top->str;
	stack->top->num = ((t_num *)(stack->top->below))->num;
	stack->top->str = ((t_num *)(stack->top->below))->str;
	((t_num *)(stack->top->below))->num = temp.num;
	((t_num *)(stack->top->below))->str = temp.str;
	if (!ss)
	{
		putstr(str(s));
		putstr(stack->s_name);
		putstr("\n");
	}
}
