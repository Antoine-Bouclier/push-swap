/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/31 09:24:56 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_putstr("Error\n"), 0);
	if (!is_correct_arg(argv))
		return (ft_putstr("Error\n"), 0);
	stack_creator(&stack_a, argv);
	if (stack_a == NULL)
		return (ft_putstr("Error, empty stack!"), 0);
	index_stack(stack_a);
	radix_sort(&stack_a, &stack_b);
	return (1);
}

// cc -I./includes src/main.c src/verif_input.c src/verif_input_utils.c src/create_stack.c src/utils.c