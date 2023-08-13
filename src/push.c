/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:14:29 by eva-001           #+#    #+#             */
/*   Updated: 2023/08/13 23:14:59 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//?		Helper functions
static t_num	*pop_top(t_stack *stack);
static void		push_node_top(t_stack *dest, t_num *node);
static void		detatch_node(t_num *node);

//?		push
/*
Pushes the top of from_stack to top of to_stack, by popping the top node
of start, and pushing it to dest
*/
void	push(t_stack *from_stack, t_stack *to_stack)
{
	t_num	*node;

	node = pop_top(from_stack);
	if (!node)
		return ;
	push_node_top(to_stack, node);
	PUTSTR(STR(p));
	PUTSTR(to_stack->s_name);
	PUTSTR("\n");
}

//?		Helper functions
/*
Removes the top node of a stack, sets the new top
returns the detached nodes(all pointers set to NULL)
 */
static t_num	*pop_top(t_stack *stack)
{
	t_num	*old_top;

	old_top = stack->top;
	if (old_top)
	{
		stack->top = stack->top->below;
		detatch_node(old_top);
		stack->size--;
		if (stack->size)
		{
			if (stack->size > 1)
			{
				stack->top->above = stack->bot;
				stack->bot->below = stack->top;
			}
			else
			{
				stack->top->above = NULL;
				stack->top->below = NULL;
			}
		}
		else
			stack->bot = NULL;
	}
	return (old_top);
}

/*
Pushes a detached node the return of pop_stack_top, top the top
of stack dest, sets the below pointer to the old_top of dest, old_top
has its above pointer set to the detached node,
 */
static void	push_node_top(t_stack *dest, t_num *node)
{
	if (dest->top)
	{
		dest->top->above = node;
		node->below = dest->top;
		node->above = dest->bot;
		dest->bot->below = node;
	}
	else
		dest->bot = node;
	dest->top = node;
	dest->size++;
}

/*
sets the node above and below pointers to null
 */
static void	detatch_node(t_num *node)
{
	node->above = NULL;
	node->below = NULL;
}
