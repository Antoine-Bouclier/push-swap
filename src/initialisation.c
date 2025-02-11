/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:48:56 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 09:14:06 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	index_stack(stack_a);
	return (stack_a);
}

static void	index_stack_bis(t_stack *current, t_stack *compare, int *index)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(current);
	while (i < size)
	{
		if (current->value > compare->value)
			(*index)++;
		compare = compare->next;
		i++;
	}
}

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;
	int		size;
	int		i;

	if (stack == NULL)
		return ;
	size = stack_size(stack);
	current = stack->next;
	current = stack;
	i = 0;
	while (i < size)
	{
		index = 0;
		compare = stack;
		index_stack_bis(current, compare, &index);
		current->index = index;
		current = current->next;
		i++;
	}
}
