/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:58:01 by eva-001           #+#    #+#             */
/*   Updated: 2023/08/13 21:26:35 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_ascending(t_stack *stack)
{
	t_num	*cur;
	int		i;

	i = 0;
	cur = stack->bot;
	while (cur->num != stack->top->num)
	{
		if (cur->num < cur->above->num)
			return (false);
		i++;
		cur = cur->above;
	}
	return (true);
}

bool	is_descending(t_stack *stack)
{
	t_num	*cur;
	int		i;

	i = 0;
	cur = stack->bot;
	while (cur->num != stack->top->num)
	{
		if (cur->num > cur->above->num)
			return (false);
		i++;
		cur = cur->above;
	}
	return (true);
}
