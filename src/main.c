/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 16:10:38 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (ft_putstr("Error\n"), 0);
	if (!is_correct_arg(argv))
		return (ft_putstr("Error\n"), 0);
	stack_creator(&stack_a, argv);
	return (1);
}

// cc -I./includes test/test_new_node.c src/create_stack.c src/utils.c