/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:27:49 by sabdelra          #+#    #+#             */
/*   Updated: 2023/03/07 04:38:09 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct s_num
{
	int		num;
	void	*below;
	void	*above;
}	t_num;

typedef struct s_stack
{
	t_num	*cur;
	t_num	*top;
	t_num	*bot;
	int		size;
}	t_stack;

typedef struct s_entry
{
	int		value;
	struct	s_entry *next;
}	t_entry;

typedef struct s_hash_table
{
	unsigned int		size;
	t_entry				**entries;
}	t_hash;

typedef struct s_scan
{
	int		longest;
	t_num	*start;
}	t_scan;

// * actions
void	swap(t_stack *stack, char name);
void	swap_s(t_stack *a, t_stack *b);
void	rot(t_stack *stack, char name);
void	rot_r(t_stack *a, t_stack *b);
void	rrot(t_stack *a, char name);
void	rrot_r(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
// * Utilities
void			create_empty_stack(t_stack *stack);
t_num			*create_node(int num);
void			insert_node(t_num *node, t_num *above, t_num *below);
void			fill_stack(t_stack *stack, char **numbers, int count);
void			print_stack(t_stack *stack, char stack_name);
void			print_rstack(t_stack *stack, char stack_name);
void			free_stack(t_stack *stack);
int				ft_atoi(const char *num);
unsigned int	hash(int num, int table_size);
t_hash			*create_hash_table(int size);
unsigned int	hash(int num, int table_size);
void			check_duplicates(t_stack *stack, t_num *node, t_hash *table);
void			free_table(t_hash *table);
int				check_sort(t_stack *stack);
// * Error
void			error_msg(void	);
void			mem_check(void *pointer);

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// * Sorting Testing
// t_scan	*scan(t_stack *a);
// void	sort_stack(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);


// * testing remove strncpy from ft_split
char	**ft_split(char *s, char del);
void	free_split(char **split);
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif

// * prio
// TODO get it to sort
// * Replace illegal
// TODO replace printf
// TODO replace strncpy
// * bugs
// TODO handle args = 1 2 "3 4 5" 6
// TODO 1 2 [5] 6 ...
// TODO operation on an empty stack
// TODO test cases empty stacks ... etc
// * optimize
// TODO use smaller hash tables, using table size might lead to alot of empty spots
// TODO remove the else if from check_duplicates function
// TODO revise the logic of pusha and pushb

