/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 02:04:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/06/19 19:15:31 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* implementing error wrapper function
void	*mem_check(void *pointer)
{
	if (!pointer)
		write(2, "Error\n", 7);
	return (pointer);
}
