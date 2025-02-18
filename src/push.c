/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:06:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/13 13:01:00 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop_from_src(t_stack **src)
{
	t_stack	*tmp;

	if (*src == NULL)
		return (NULL);
	tmp = *src;
	*src = (*src)->next;
	if (*src != tmp)
	{
		(*src)->precedent = tmp->precedent;
		tmp->precedent->next = *src;
	}
	else
		*src = NULL;
	return (tmp);
}

static void	push_to_dest(t_stack **dest, t_stack *tmp)
{
	if (*dest)
	{
		tmp->next = *dest;
		tmp->precedent = (*dest)->precedent;
		(*dest)->precedent->next = tmp;
		(*dest)->precedent = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->precedent = tmp;
	}
	*dest = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	tmp = pop_from_src(src);
	if (tmp != NULL)
		push_to_dest(dest, tmp);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
