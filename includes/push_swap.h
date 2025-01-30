/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:35:17 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 09:25:48 by abouclie         ###   ########.fr       */
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
void	ft_putstr_fd(char *s, int fd);

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

#endif