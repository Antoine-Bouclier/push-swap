/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:52:16 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/05 13:12:41 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_stack(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

t_stack	*get_second_to_last_stack(t_stack *stack)
{
	t_stack	*second_to_last;

	if (!stack)
		return (NULL);
	second_to_last = stack;
	while (second_to_last->next->next)
	{
		second_to_last = second_to_last->next;
	}
	return (second_to_last);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_last_stack(*stack);
	tail->next = new;
}

int	stack_size(t_stack *stack)
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