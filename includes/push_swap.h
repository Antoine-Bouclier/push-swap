/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:17 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/05 13:13:28 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}	t_stack;

/* Instruction */
void	ss(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);

void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);


/* Verification input */
int	is_correct_arg(char **argv);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isdigit(int c);

/* utils */
void	ft_putstr(char *s);
int	ft_atoi(const char *nptr);
void	exit_error(t_stack **stack_a, t_stack **stack_b);

/* Initialisation */
t_stack	*fill_stack_values(int ac, char **av);
void	index_stack(t_stack *stack);

/* new stack */
t_stack	*get_last_stack(t_stack *stack);
t_stack	*get_second_to_last_stack(t_stack *stack);
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int	stack_size(t_stack *stack);

/* Find biggest */
int	get_max_digits(t_stack *stack);
t_stack	*get_biggest(t_stack *stack_a);

/* Radix sort */
void radix_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_sort_binary(t_stack **stack_a, t_stack **stack_b);

/* Radix sort utils */
int	normalize_values(t_stack *stack);
int	ft_abs(int	min_value);
int	get_digit(int number, int digit_position);

void	free_stack(t_stack **stack);

/*! Temporaire !*/
void print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif