/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:53 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/07 10:57:58 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_biggest(t_stack *stack_a)
{
	t_stack	*biggest;
	t_stack	*current;
	int		first_pass;
	
	first_pass = 1;
	if (!stack_a)
		return (NULL);
	biggest = stack_a;
	current = stack_a->next;
	while (current != stack_a || first_pass)
	{
		if (current->value > biggest->value)
			biggest = current;
		current = current->next;
		first_pass = 0;
	}
	return (biggest);
}

int	get_max_digits(t_stack *stack)
{
	t_stack *biggest;
	int		digits;
	int		max;

	if (!stack)
		return (-1);
	digits = 1;
	biggest = get_biggest(stack);
	max = biggest->value;
	while (max >= 10)
	{
		digits++;
		max /= 10;
	}
	return digits;
}