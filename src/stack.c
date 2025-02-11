/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:52:16 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 09:40:08 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = new;
	new->precedent = new;
	return (new);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->precedent = (*stack)->precedent;
	(*stack)->precedent->next = new;
	(*stack)->precedent = new;
}

int	stack_size(t_stack *stack)
{
	int		size;
	int		first_pass;
	t_stack	*current;

	size = 0;
	first_pass = 1;
	if (stack == NULL)
		return (0);
	current = stack;
	while (current != stack || first_pass)
	{
		size++;
		current = current->next;
		first_pass = 0;
	}
	return (size);
}
