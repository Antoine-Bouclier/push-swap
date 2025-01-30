/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:44:36 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 15:22:39 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_stack(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

t_stack	*get_second_to_last_stack(t_stack *stack)
{
	t_stack	*second_to_last;

	if (!stack)
		return (NULL);
	second_to_last = stack;
	while (second_to_last->next->next)
	{
		second_to_last = second_to_last->next;
	}
	return (second_to_last);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int					i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		if (result > __LONG_LONG_MAX__ && sign == -1)
			return (0);
		else if (result > __LONG_LONG_MAX__)
			return (-1);
		i++;
	}
	return ((int)result * sign);
}