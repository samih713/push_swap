/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:36:37 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/06 04:27:15 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define PRINTON


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
	b = malloc(sizeof(t_stack));
	mem_check(b);
	create_empty_stack(a);
	create_empty_stack(b);
	fill_stack(a, argv, argc - 1);
	// *******************************************
	#ifdef PRINTON
	print_stack(a, 'a');
	print_stack(b, 'b');
	sort(a, b);
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





// * 9 7 31 2 5 6 3 13 11 65


// * [7] 2 5 6 3
// *
// *
// *
// *
// *
// *
// *
// ! how to minimize pa
// ! stack b has to be numbers less than the pivot
// ! b in descending order
// * 31 13 11 65 9
// *
// *
// *
// *
// *







