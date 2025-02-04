/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:18:22 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/04 17:44:11 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size = stack_size(*stack_a);
	int	max_num = 0;
	t_stack	*current = *stack_a;
	int digit_position = 0;
	int min_value;

	min_value = normalize_values(*stack_a);
	while (current)
	{
		if (current->value > max_num)
			max_num = current->value;
		current = current->next;
	}
	int max_digits = 0;
	while (max_num > 0)
	{
		max_num /= 10;
		max_digits++;
	}
	while (digit_position < max_digits)
	{
		for (int j = 0; j < size; j++)
		{
			int num = (*stack_a)->value;
			if (get_digit(num, digit_position) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		digit_position++;
	}
	current = *stack_a;
	while (current)
		current->value -= ft_abs(min_value);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		min_value;
	int		digit_position;
	int		max_num;
	int		max_digits;
	t_stack	*current;

	min_value = normalize_values(*stack_a);
	digit_position = 0;
	current = *stack_a;
	max_digits = 0;
	max_num = get_max_digits(stack_a);
	while (max_num > 0)
	{
		max_num /= 10;
		max_digits++;
	}
	while (digit_position < max_digits)
	{
		
	}
}
