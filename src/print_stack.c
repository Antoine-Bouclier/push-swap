/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:28:46 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/07 11:00:51 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *temp_a = stack_a;
    t_stack *temp_b = stack_b;
    int     first_pass = 1;
    
    printf("Stack A | Stack B\n");
    printf("--------|--------\n");
    
    while (temp_a != stack_a || temp_b != stack_b || first_pass)
    {
        if (temp_a)
        {
            printf("%7d ", temp_a->value);
            temp_a = temp_a->next;
        }
        else
            printf("        ");
        
        printf("|");
        
        if (temp_b)
        {
            printf(" %7d", temp_b->value);
            temp_b = temp_b->next;
        }
        
        printf("\n");
        first_pass = 0;
    }
    printf("\n");
}
