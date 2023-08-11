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

static int	count_arguments(char **argv);
static char	**set_args(char **argv, int count);

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	int		count;
	char	**numbers;

	stack_init(&a, str(a));
	stack_init(&b, str(b));
	if (!argv[1] || !*(argv[1]))
		return (0);
	count = count_arguments(argv);
	numbers = set_args(argv, count);
	if (stack_fill(&a, numbers, count))
	{
		if (is_ascending(&a))
			return (0);
		if (count > 5)
			sort(&a, &b);
		else
			sort_small(&a, &b);
	}
	else
		write(2, "Error\n", 6);
	free_numbers(numbers, count);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

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
		while (ft_strchr(*argv, ' ') && (*argv)[i])
		{
			while (ft_strchr(ws, (*argv)[i]) && (*argv)[i])
				i++;
			if ((*argv)[i] && !ft_strchr(ws, (*argv)[i]))
			{
				ret += 1;
				while ((*argv)[i] && !ft_strchr(ws, (*argv)[i]))
					i++;
			}
		}
		((*argv)[i] && (ret += 1));
	}
	return (ret);
}

static char	**set_args(char **argv, int count)
{
	char	**ret;
	int		i;
	int		j;
	int		size;
	char	*ws;

	ws = " \t\n\r\v";
	j = 0;
	ret = mem_check(malloc(sizeof(char *) * count));
	while (*(++argv))
	{
		i = 0;
		while (ft_strchr(*argv, ' ') && (*argv)[i])
		{
			while (ft_strchr(ws, (*argv)[i]) && (*argv)[i])
				i++;
			if ((*argv)[i] && !ft_strchr(ws, (*argv)[i]))
			{
				size = 0;
				while ((*argv)[i + size] && !ft_strchr(ws, (*argv)[i + size]))
					size++;
				ret[j] = mem_check(malloc(sizeof(char) * size + 1));
				ft_memmove(ret[j], (*argv) + i, size);
				ret[j][size] = 0;
				j++;
				i += size;
			}
		}
		if ((*argv)[i])
		{
			size = ft_strlen((*argv));
			ret[j] = mem_check(malloc(sizeof(char) * size + 1));
			ft_memmove(ret[j], (*argv), size);
			ret[j][size] = 0;
			j++;
		}
	}
	return (ret);
}

