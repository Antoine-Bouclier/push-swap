/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:06:29 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/12 11:16:34 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*stack_a)->value;
	mid = (*stack_a)->next->value;
	bottom = (*stack_a)->precedent->value;
	if (top > mid && mid < bottom && top < bottom)
		sa(stack_a);
	else if (top > mid && mid > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bottom && top > bottom)
		ra(stack_a);
	else if (top < mid && mid > bottom && top < bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bottom && top > bottom)
		rra(stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	element_to_push;

	element_to_push = stack_size(*stack_a) - 3;
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || ((*stack_a)->index == 1
				&& (*stack_a)->index < element_to_push))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	while (stack_size(*stack_b) != 0)
	{
		if ((*stack_b)->index == 0 && stack_size(*stack_b) > 1)
			sb(stack_b);
		pa(stack_a, stack_b);
	}
}
