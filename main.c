// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:36:37 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/12 03:34:47 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		printf("%d : %s\n", i, argv[i]);
	t_stack a;
	t_stack b;
	stack_init(&a, str(a));
	stack_init(&b, str(b));
	if (!argv[1] || !*(argv[1]))
		return 0;
	stack_fill(&a, argv, argc - 1);
	mechanicalTurk(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
