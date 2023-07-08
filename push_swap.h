/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:27:49 by sabdelra          #+#    #+#             */
/*   Updated: 2023/07/08 01:18:51 by sabdelra         ###   ########.fr       */
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

#define str(s) #s
#define putstr(string) (write(1, string, ft_strlen(string)))
#define puterr(string) (write(2, string, ft_strlen(string)))

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
	struct	s_entry	*next;
}	t_entry;

typedef struct s_hash_table
{
	unsigned int		size;
	t_entry				**entries;
}	t_hash;

//* actions
void	swap(t_stack *stack);
void	swap_s(t_stack *a, t_stack *b);
void	rot(t_stack *stack);
void	rot_r(t_stack *a, t_stack *b);
void	rrot(t_stack *stack);
void	rrot_r(t_stack *a, t_stack *b);
void	push(t_stack *from_stack, t_stack *to_stack);

//* sources
void			stack_init(t_stack *stack, char *name);
void			stack_fill(t_stack *stack, char **numbers, int count);
void			free_stack(t_stack *stack);
void			free_table(t_hash *table);
int				_ft_atoi(const char *num, t_stack *stack, t_hash *table);
size_t			ft_strlen(char *str);
bool			is_ascending(t_stack *stack);
bool			is_descending(t_stack *stack);
void			*mem_check(void *pointer);
void			print_stack(t_stack *stack);
void			rprint_stack(t_stack *stack);

// * Sorting
void mechanicalTurk(t_stack *a, t_stack *b);

#endif

// big
// TODO all exits print to stderr
// TODO sort 2 numbers

// small
// TODO handle args = 1 2 "3 4 5" 6
// TODO all functions should have a hover message
	// Description , return value, error, special notes (man style)
	// params should be self explantory from names
// TODO
