/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 00:51:42 by eva-001           #+#    #+#             */
/*   Updated: 2023/08/12 00:27:48 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Allocates memory for a new t_stack struct and setting its top, bottom,
and size fields to NULL, NULL, and 0. Returns a pointer to the newly
created stack. If the malloc operation fails, prints an error message
to stderr and returns NULL.
*/
void	stack_init(t_stack *stack, char *name)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->s_name = name;
	stack->size = 0;
}
