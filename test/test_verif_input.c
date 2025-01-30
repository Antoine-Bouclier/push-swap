/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_verif_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:50:02 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 12:52:33 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int	main(int argc, char **argv)
{
	if (argc < 2)
    {
        printf(RED "Usage: %s <arg1> <arg2> ...\n" RESET, argv[0]);
        return 1;
    }

    if (is_correct_arg(argv))
        printf(GREEN "Tous les arguments sont correct.\n" RESET);
    else
        printf(RED "Au moins un argument n'est pas correct.\n" RESET);

    return 0;
}