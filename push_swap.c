/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:36:37 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/10 04:44:52 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define PRINTOFF

static void	free_stacks(t_stack *a, t_stack *b);

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	// * if no arguments given return prompt
	if (!argv[1])
		return (0);
	// * stack creation and filling from arguments
	a = malloc(sizeof(t_stack));
	mem_check(a);
	create_empty_stack(a);
	fill_stack(a, argv, argc - 1);
	// * 2nd stack after dup check, to avoid free
	b = malloc(sizeof(t_stack));
	mem_check(b);
	create_empty_stack(b);
	// sort(a, b);
	// *******************************************
	#ifdef PRINTON
	print_stack(a, 'a');
	print_stack(b, 'b');
	rrot(a, 'a');
	rrot(a, 'a');
	rrot(a, 'a');
	print_stack(a, 'a');
	print_stack(b, 'b');
	rrot(b, 'b');
	rrot(b, 'b');
	rrot(b, 'B');
	print_stack(a, 'a');
	print_stack(b, 'b');
	#endif
	// * free the stacks
	free_stacks(a, b);
	return (0);
}

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}








