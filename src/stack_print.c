/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:12:48 by eva-001           #+#    #+#             */
/*   Updated: 2023/06/19 18:40:00 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ? helper functions
static void	write_stack_name(char *name);

/*
Prints the stack from top -> bot
 */
void	print_stack(t_stack *stack)
{
	t_num	*temp;
	int		i;

	i = 0;
	temp = stack->top;
	while (i < stack->size)
	{
		write(1, "      ", 7);
		putstr(temp->str);
		write(1, "\n", 1);
		temp = temp->below;
		i++;
	}
	write_stack_name(stack->s_name);
}

/*
Prints stack in reverse, bot -> top
 */
void	rprint_stack(t_stack *stack)
{
	t_num	*temp;
	int		i;

	i = 0;
	temp = stack->top;
	while (i < stack->size)
	{
		write(1, "      ", 7);
		putstr(temp->str);
		write(1, "\n", 1);
		temp = temp->below;
		i++;
	}
	write_stack_name(stack->s_name);
}

/*
helper to write the stack name at the bottom
 */
static void	write_stack_name(char *name)
{
	write(1, "--- stack (", 12);
	if (name)
		putstr(name);
	write(1, ") ---\n", 7);
}
