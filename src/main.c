/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/05 15:10:19 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*current;
	int		min_value;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_putstr("Error\n"), 0);
	if (!is_correct_arg(argv))
		return (ft_putstr("Error arg\n"), 0);
	stack_a = fill_stack_values(argc, argv);
	if (stack_a == NULL)
		return (ft_putstr("Error, empty stack!"), 0);
	min_value = normalize_values(stack_a);
	radix_sort_binary(&stack_a, &stack_b);
	current = stack_a;
	while (current)
    {
        current->value -= ft_abs(min_value);
        current = current->next;
    }
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
