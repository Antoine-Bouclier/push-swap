/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:06:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/29 12:17:18 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_stack	*tmp;

	tmp = src->next;
	src->next = dest->next;
	dest->next = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(*stack_a, *stack_b);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push(*stack_b, *stack_a);
}