/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 09:14:35 by abouclie         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_putstr("Error\n"), 0);
	if (!is_correct_arg(argv))
		return (ft_putstr("Error arg\n"), 0);
	stack_a = fill_stack_values(argc, argv);
	if (stack_a == NULL)
		return (ft_putstr("Error, empty stack!"), 0);
	radix_sort_binary(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
