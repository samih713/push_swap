/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:04:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/07/07 21:15:35 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* implementing error wrapper function
void	*mem_check(void *pointer)
{
	if (!pointer)
		write(2, "Error\n", 6);
	return (pointer);
}
