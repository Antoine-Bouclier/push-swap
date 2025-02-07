/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:06:35 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/07 10:47:54 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return;
	tmp = *src;
	*src = (*src)->next;
	if (*src != tmp)
	{
		(*src)->precedent = tmp->precedent;
		tmp->precedent->next = *src;
	}
	else
		*src = NULL;
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



void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}