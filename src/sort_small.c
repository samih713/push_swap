/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:58:36 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/12 00:27:07 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack *a, t_stack *b)
{
	if (is_ascending(a))
		return ;
	if (a->top->num > a->top->below->num)
		swap(a);
	push(a, b);
	if (a->top->num > a->top->below->num)
		swap(a);
	push(b, a);
}
