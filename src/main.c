/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/12 11:18:20 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		first_pass;

	current = *stack;
	first_pass = 1;
	if (!stack || !(*stack))
		return ;
	while (current != *stack || first_pass)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		first_pass = 0;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		count;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	count = 0;
	while (count < stack_size(stack) - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		count++;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_size <= 5 && !is_sorted(*stack_a))
		sort_five(stack_a, stack_b);
	else if (stack_size > 5 && !is_sorted(*stack_a))
		radix_sort_binary(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (!is_correct_arg(argv))
	{
		ft_putstr("Error arg\n");
		return (0);
	}
	stack_a = fill_stack_values(argc, argv);
	if (stack_a == NULL)
	{
		ft_putstr("Error, empty stack!");
		return (0);
	}
	push_swap(&stack_a, &stack_b, stack_size(stack_a));
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
