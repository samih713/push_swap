/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:50:21 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 23:14:59 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rrot(t_stack *stack, bool rrr);

/*
Wrapper around _rrot with rrr set to 0, to print move name
 */
void	rrot(t_stack *stack)
{
	_rrot(stack, 0);
}

/*
Performs reverse rotation on both stacks
 */
void	rrot_r(t_stack *a, t_stack *b)
{
	_rrot(a, 1);
	_rrot(b, 1);
	PUTSTR(STR(rrr));
	PUTSTR("\n");
}

//?		Internal function
/*
Takes a single stack as an argument and performs a reverse rotation
operation on it. It moves the bottom element of the stack to the top, and shift
all elements down by 1.
If the stack has fewer than two elements it does nothing.
The rr parameter is used to indicate whether it is double rotate move or no, this
is needed for printing move name
*/
static void	_rrot(t_stack *stack, bool rrr)
{
	t_num	*old_top;

	if (stack->size < 2)
		return ;
	old_top = stack->top;
	stack->top = stack->bot;
	stack->bot = stack->bot->above;
	old_top->above = stack->top;
	stack->top->below = old_top;
	if (!rrr)
	{
		PUTSTR(STR(rr));
		PUTSTR(stack->s_name);
		PUTSTR("\n");
	}
}
