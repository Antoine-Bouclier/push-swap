/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:23:41 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/31 09:11:09 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_node(t_stack **stack, int n, int index)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	new_node->value = n;
	new_node->index = index;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = get_last_stack(*stack);
		last->next = new_node;
	}
}

void	stack_creator(t_stack **a, char **argv)
{
	int	i;
	int	num;
	int	index;

	index = 0;
	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		add_node(a, num, index);
		i++;
		index++;
	}
}

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int	index;

	if (stack == NULL)
		return ;
	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}