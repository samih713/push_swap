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

/* int main(int argc, char **argv)
{
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
} */

#include <string.h>

static int	count_arguments(char **argv)
{
	int		ret;
	int		i;
	char	*ws;

	ret = 0;
	ws = " \t\n\r\v";
	while (*(++argv))
	{
		i = 0;
		while (strchr(*argv, ' ') && (*argv)[i])
		{
			while (strchr(ws, (*argv)[i]) && (*argv)[i])
				i++;
			if ((*argv)[i] && !strchr(ws, (*argv)[i]))
			{
				ret += 1;
				while ((*argv)[i] && !strchr(ws, (*argv)[i]))
					i++;
			}
		}
		((*argv)[i] && (ret += 1));
	}
	return (ret);
}

/* int main(int argc, char **argv)
{
	printf("%d\n", count_arguments(argv));
} */
