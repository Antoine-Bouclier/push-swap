/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:57:54 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/11 09:41:13 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	arg_is_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	verif_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	verif_duplicates_zero(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '-' || argv[i] == '+')
			i++;
		if (argv[i] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_correct_arg(char **argv)
{
	int	i;
	int	nb_zero;

	i = 1;
	nb_zero = 0;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		if (verif_duplicates_zero(argv[i]))
			nb_zero++;
		if (nb_zero > 1)
			return (0);
		i++;
	}
	if (!verif_duplicates(argv))
		return (0);
	return (1);
}
