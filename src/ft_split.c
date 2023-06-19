/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eva-001 <eva-001@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:52:16 by sabdelra          #+#    #+#             */
/*   Updated: 2023/06/19 19:36:17 by eva-001          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! REPLACE FT_STRNCPY
#include "push_swap.h"

static int	count_words(char *s, char del);
static int	size_word(char **s, char del);

char	**ft_split(char *s, char del)
{
	char	**split;
	int		arr_size;
	int		i;
	int		wrd_len;

	arr_size = count_words(s, del);
	split = mem_check(malloc(sizeof(char *) * arr_size + 1));
	split[arr_size] = NULL;
	i = 0;
	while (i < arr_size)
	{
		wrd_len = size_word(&s, del);
		split[i] = mem_check(malloc(sizeof(char) * wrd_len + 1));
		strncpy(split[i], s, wrd_len); //! replace strncpy
		i++;
		s += wrd_len;
	}
	return (split);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

static int	count_words(char *s, char del)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == del)
			i++;
		if (s[i] && s[i] != del)
		{
			n++;
			while (s[i] && s[i] != del)
				i++;
		}
	}
	return (n);
}

static int	size_word(char **s, char del)
{
	int	n;

	n = 0;
	while (**s == del)
		(*s)++;
	while ((*s)[n] && (*s)[n] != del)
		n++;
	return (n);
}
