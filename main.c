/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:34:11 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 23:14:25 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_arguments(char **argv);
static char	**set_args(char **argv, int count);
static void	clean_up(char **numbers, int count, t_stack *a, t_stack *b);

int	main(int __attribute__((unused))argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		count;
	char	**n;

	stack_init(&a, STR(a));
	stack_init(&b, STR(b));
	if (!argv[1] || !*(argv[1]))
		return (0);
	count = count_arguments(argv);
	n = set_args(argv, count);
	if (stack_fill(&a, n, count))
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
	clean_up(n, count, &a, &b);
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

// Copy non-whitespace content and update the position
static void	copy_content(char **ret, char *av, int *i, int *j)
{
	int	sz;

	sz = 0;
	while (av[*i + sz] && !ft_strchr(" \t", av[*i + sz]))
		sz++;
	ret[*j] = mem_check(malloc(sizeof(char) * sz + 1));
	ft_memmove(ret[*j], av + *i, sz);
	ret[*j][sz] = 0;
	*j += 1;
	*i += sz;
}

static char	**set_args(char **av, int count)
{
	char	**ret;
	int		c[2];
	int		sz;

	c[J] = 0;
	ret = mem_check(malloc(sizeof(char *) * count));
	while (*(++av))
	{
		c[I] = 0;
		while (ft_strchr(*av, ' ') && (*av)[c[I]])
		{
			while (ft_strchr(" \t", (*av)[c[I]]) && (*av)[c[I]])
				c[I]++;
			if ((*av)[c[I]] && !ft_strchr(" \t", (*av)[c[I]]))
				copy_content(ret, *av, &c[I], &c[J]);
		}
		if ((*av)[c[I]])
		{
			sz = ft_strlen((*av));
			ret[c[J]] = mem_check(malloc(sizeof(char) * sz + 1));
			ft_memmove(ret[c[J]], (*av), sz);
			ret[c[J]++][sz] = 0;
		}
	}
	return (ret);
}

static void	clean_up(char **n, int c, t_stack *a, t_stack *b)
{
	free_numbers(n, c);
	free_stack(a);
	free_stack(b);
}
