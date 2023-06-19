/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:07:59 by eva-001           #+#    #+#             */
/*   Updated: 2023/06/19 19:57:16 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_table(t_hash *table)
{
	unsigned int	index;
	t_entry			*next;

	index = 0;
	if (table)
	{
		while (index < table->size)
		{
			while (table->entries[index])
			{
				next = table->entries[index]->next;
				free(table->entries[index]);
				table->entries[index] = next;
			}
			index++;
		}
		free(table->entries);
	}
}

void	free_stack(t_stack *stack)
{
	t_num	*temp;
	int		i;

	i = 0;
	temp = stack->bot;
	while (i < stack->size)
	{
		stack->bot = stack->bot->above;
		free(temp);
		temp = stack->bot;
		i++;
	}
}
