/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:23:41 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 16:04:53 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	new_node->value = n;
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

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		add_node(a, num);
		i++;
	}
}