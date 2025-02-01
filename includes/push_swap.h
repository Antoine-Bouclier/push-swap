/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:17 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/01 18:08:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
}	t_stack;

t_stack	*get_last_stack(t_stack *stack);
t_stack	*get_second_to_last_stack(t_stack *stack);
void	ft_putstr(char *s);
int		ft_atoi(const char *nptr);

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

void	stack_creator(t_stack **a, char **argv);
void	index_stack(t_stack *stack);
t_stack	*get_biggest(t_stack *stack_a);
int	get_max_digits(t_stack *stack);
static int	stack_size(t_stack *stack);

int	ft_isdigit(int c);
int	ft_strcmp(const char *s1, const char *s2);
int	is_correct_arg(char **argv);

#endif