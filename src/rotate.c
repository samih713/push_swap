/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:52:26 by eva-001           #+#    #+#             */
/*   Updated: 2023/05/06 04:46:51 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//?		Internal function
static void	_rot(t_stack *stack, bool rr);

//?		rotate
/*
Wrapper around _rot with rr set to 0, to print move name
 */
void	rot(t_stack *stack)
{
	_rot(stack, 0);
}

/*
Performs rotation on both stacks
 */
void	rot_r(t_stack *a, t_stack *b)
{
	_rot(a, 1);
	_rot(b, 1);
	putstr(str(rr));
	putstr("\n");
}

//?		Internal function
/*
Takes a single stack as an argument and performs a rotation
operation on it. It moves the top element of the stack to the bottom, and shift
all elements up by 1.
If the stack has fewer than two elements it does nothing.
The rr parameter is used to indicate whether it is double rotate move or no, this
is needed for printing move name
*/
static void	_rot(t_stack *stack, bool rr)
{
	t_num	*old_bot;

	if (stack->size < 2)
		return ;
	old_bot = stack->bot;
	stack->bot = stack->top;
	stack->top = stack->top->below;
	old_bot->below = stack->bot;
	stack->bot->above = old_bot;
	if (!rr)
	{
		putstr(str(r));
		putstr(stack->s_name);
		putstr("\n");
	}
}
