/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:17:21 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/12 00:17:25 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//?		Helper functions
static int	atoi_fail(int *err_atoi);
static bool	is_digit(char c);
static bool	is_sign(char c);

/*
atoi handles the INT_MAX and INT_MIN
contains address of stack as argument in case it needs to exit

only accepts "+1" or similar
atoi needs stack and table to free on exit
underscore because its very specific and only intended to be used by fill_table
*/
int	_ft_atoi(const char *num, t_stack *stack, t_hash *table, int *err_atoi)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	*err_atoi = 0;
	if (is_sign(num[i]))
	{
		sign = -1 * (num[i] == '-');
		i++;
	}
	if (!num[i])
		return (atoi_fail(err_atoi));
	while (is_digit(num[i]))
	{
		result = (num[i++] - '0') + (result * 10);
		if (!is_digit(num[i - 1]) || ((result * sign != INT_MIN)
				&& ((result * sign < INT_MIN) || result > INT_MAX)))
			return (atoi_fail(err_atoi));
	}
	if (num[i])
		return (atoi_fail(err_atoi));
	return (result * sign);
}

/*
frees allocated nodes from loading arguments, before exiting
with failure and invalid integer
*/
static int	atoi_fail(int *err_atoi)
{
	*err_atoi = 1;
	return (0);
}

static bool	is_sign(char c)
{
	return (c == '-' || c == '+');
}

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
