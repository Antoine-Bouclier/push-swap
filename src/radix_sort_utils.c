/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:52:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/04 12:57:43 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_digit(int number, int digit_position)
{
	int divisor;
	
	divisor = 1;
	while (digit_position > 0) {
		divisor *= 10;
		digit_position--;
	}
	return ((number / divisor) % 10);
}

static int	stack_size(t_stack *stack)
{
	int count;
	t_stack *current;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
