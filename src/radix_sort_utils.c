/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:52:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 09:38:10 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_digit(int number, int digit_position)
{
	int	divisor;

	divisor = 1;
	while (digit_position > 0)
	{
		divisor *= 10;
		digit_position--;
	}
	return ((number / divisor) % 10);
}

int	ft_abs(int min_value)
{
	int	absolute_value;

	if (min_value < 0)
		absolute_value = min_value * -1;
	else
		absolute_value = min_value;
	return (absolute_value);
}

int	normalize_values(t_stack *stack)
{
	int		min_value;
	t_stack	*current;

	min_value = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	current = stack;
	while (current)
	{
		current->value += ft_abs(min_value);
		current = current->next;
	}
	return (min_value);
}
