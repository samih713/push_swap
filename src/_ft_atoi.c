/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:45:34 by eva-001           #+#    #+#             */
/*   Updated: 2023/07/07 21:16:55 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//?		Helper functions
static void	exit_clean(t_stack *stack, t_hash *table);
static bool	is_digit(char c);
static bool	is_sign(char c);

/*
atoi handles the INT_MAX and INT_MIN
contains address of stack as argument in case it needs to exit

only accepts "+1" or similar
atoi needs stack and table to free on exit
underscore because its very specific and only intended to be used by fill_table
*/
int	_ft_atoi(const char *num, t_stack *stack, t_hash *table)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (is_sign(num[i]))
	{
		if (num[i] == '-')
			sign = -1;
		i++;
	}
	if (!num[i])
		exit_clean(stack, table);
	while (is_digit(num[i]))
	{
		if (!is_digit(num[i])
			|| (result > INT_MAX || (result * sign < INT_MIN)))
			exit_clean(stack, table);
		result = (num[i++] - '0') + (result * 10);
	}
	if (num[i])
		exit_clean(stack, table);
	return (result * sign);
}

/*
frees allocated nodes from loading arguments, before exiting
with failure and invalid integer
*/
static void	exit_clean(t_stack *stack, t_hash *table)
{
	free_stack(stack);
	free_table(table);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static bool	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
