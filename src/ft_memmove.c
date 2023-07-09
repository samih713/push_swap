/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:31:05 by sabdelra          #+#    #+#             */
/*   Updated: 2023/07/08 07:31:22 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*source;
	char	*destination;

	if (!src && !dst)
		return (NULL);
	i = 0;
	source = (char *) src;
	destination = (char *) dst;
	if (src < dst)
		while (len--)
			destination[len] = source[len];
	else
	{
		while (len--)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (dst);
}
