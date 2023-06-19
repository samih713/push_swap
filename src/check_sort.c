/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:58:01 by eva-001           #+#    #+#             */
/*   Updated: 2023/06/19 18:38:41 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Checks if the stack is ordered fromt top->bot in ascending order returns false if not sorted, true if sorted or empty
 */
bool		is_ascending(t_stack *stack)
{
	t_num *cur;
	int i;

	i = 0;
	cur = stack->bot;
	while (i < stack->size - 1)
	{
		if (cur->num < cur->above->num)
			return (false);
		i++;
		cur = cur->above;
	}
	return (true);
}

/*
Checks if the stack is ordered from top->bot in descending order returns false if not sorted, true if sorted or empty
 */
bool		is_descending(t_stack *stack)
{
	t_num *cur;
	int i;

	i = 0;
	cur = stack->bot;
	while (i < stack->size - 1)
	{
		if (cur->num > cur->above->num)
			return (false);
		i++;
		cur = cur->above;
	}
	return (true);
}
