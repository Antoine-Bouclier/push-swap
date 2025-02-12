/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:56:46 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 10:08:02 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_stack_a(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	size;
	int	bit;

	size = stack_size(*stack_a);
	while (size--)
	{
		bit = ((*stack_a)->index >> i) & 1;
		if (bit == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

static void	process_stack_b(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	size;
	int	bit;

	size = stack_size(*stack_b);
	while (size--)
	{
		bit = ((*stack_b)->index >> i) & 1;
		if (bit == 1)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}

void	radix_sort_binary(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	i;
	int	max_index;

	max_bits = 0;
	max_index = get_biggest(*stack_a)->index;
	while (max_index >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		process_stack_a(stack_a, stack_b, i);
		i++;
		if (i < max_bits)
			process_stack_b(stack_a, stack_b, i);
	}
	while (stack_size(*stack_b) > 0)
	{
		pa(stack_a, stack_b);
	}
}
