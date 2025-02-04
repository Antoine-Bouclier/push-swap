/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:02:48 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/04 12:46:44 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		max_index;
	t_stack	*current;
	
	max_index = 0;
	current = *stack_a;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	while (max_index >= 0)
	{
		current = *stack_a;
		while (current)
		{
			if (current->index == max_index)
			{
				pb(stack_b, stack_a);
				break ;
			}
			else
				current = current->next;
		}
		max_index--;
	}
	push_all_to_a(stack_a, stack_b);
}

void	push_all_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
