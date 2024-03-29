/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:27:49 by sabdelra          #+#    #+#             */
/*   Updated: 2023/08/13 23:15:12 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <assert.h>
# include <stdbool.h>

# define STR(s) #s
# define PUTSTR(string) (write(1, string, ft_strlen(string)))

# define I 0
# define J 1

//* stack
/*
t_num are members of t_stack,
t_stack is a wrapper around the doubly linked list created by t_nums
it has pointers to the top and bot of the list, and the current size
of the list
 */
typedef struct s_num
{
	int				num;
	int				rank;
	char			*str;
	struct s_num	*below;
	struct s_num	*above;
}	t_num;

typedef struct s_stack
{
	t_num	*top;
	t_num	*bot;
	char	*s_name;
	int		size;
}	t_stack;

//* hash table
typedef struct s_entry
{
	int				value;
	struct s_entry	*next;
}	t_entry;

typedef struct s_hash_table
{
	unsigned int		size;
	t_entry				**entries;
}	t_hash;

//* actions
void			swap(t_stack *stack);
void			swap_s(t_stack *a, t_stack *b);
void			rot(t_stack *stack);
void			rot_r(t_stack *a, t_stack *b);
void			rrot(t_stack *stack);
void			rrot_r(t_stack *a, t_stack *b);
void			push(t_stack *from_stack, t_stack *to_stack);

//* sources
void			stack_init(t_stack *stack, char *name);
int				stack_fill(t_stack *stack, char **numbers, int count);
void			free_stack(t_stack *stack);
void			free_table(t_hash *table);
int				_ft_atoi(const char *num, int *err_atoi);
size_t			ft_strlen(char *str);
bool			is_ascending(t_stack *stack);
bool			is_descending(t_stack *stack);
void			*mem_check(void *pointer);
char			*ft_strchr(const char *s, int c);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			free_numbers(char **numbers, int size);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
int				check_duplicates(t_num *node, t_hash *table);

// * Sorting
void			sort_small(t_stack *a, t_stack *b);
void			sort(t_stack *a, t_stack *b);

#endif
