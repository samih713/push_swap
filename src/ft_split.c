/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:52:16 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/12 00:34:58 by sabdelra         ###   ########.fr       */
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
		ft_strlcpy(split[i], s, wrd_len);
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
