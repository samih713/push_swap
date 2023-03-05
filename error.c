/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:04:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/26 23:59:04 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(void)
{
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	mem_check(void *pointer)
{
	if (!pointer)
	{
		write(2, "Memory allocation failed\n", 26);
		exit(EXIT_FAILURE);
	}
}
