/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:52:50 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/12 11:23:05 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_digit(int number, int digit_position)
{
	int	divisor;

	divisor = 1;
	while (digit_position > 0)
	{
		divisor *= 10;
		digit_position--;
	}
	return ((number / divisor) % 10);
}
