/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:15:56 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 09:27:05 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

t_stack *create_stack(int *values, int size)
{
    t_stack *head = NULL;
    t_stack *current = NULL;
    for (int i = 0; i < size; i++)
    {
        t_stack *new_node = malloc(sizeof(t_stack));
        new_node->value = values[i];
        new_node->index = i;
        new_node->next = NULL;
        if (head == NULL)
            head = new_node;
        else
            current->next = new_node;
        current = new_node;
    }
    return head;
}
void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("\n");
}


void print_stack_color(t_stack *stack, int highlight_first_two, int before_operation)
{
    int count = 0;
    while (stack)
    {
        if (highlight_first_two && count < 2)
        {
            if (before_operation)
                printf(YELLOW "Value: %d, Index: %d\n" RESET, stack->value, stack->index);
            else
                printf(GREEN "Value: %d, Index: %d\n" RESET, stack->value, stack->index);
        }
        else
            printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
        count++;
    }
    printf("\n");
}

int main()
{
    // Test sa
    int values_a[] = {3, 2, 1, 4};
    t_stack *stack_a = create_stack(values_a, 4);
    printf("Stack A before sa:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight in yellow
    sa(&stack_a);
    printf("Stack A after sa:\n");
    print_stack_color(stack_a, 1, 0);  // Highlight in green

    // Test sb
    int values_b[] = {8, 7, 6, 5};
    t_stack *stack_b = create_stack(values_b, 4);
    printf("Stack B before sb:\n");
    print_stack_color(stack_b, 1, 1);  // Highlight in yellow
    sb(&stack_b);
    printf("Stack B after sb:\n");
    print_stack_color(stack_b, 1, 0);  // Highlight in green

    // Test ss
    printf("Stack A and B before ss:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight in yellow
    print_stack_color(stack_b, 1, 1);  // Highlight in yellow
    ss(&stack_a, &stack_b);
    printf("Stack A and B after ss:\n");
    print_stack_color(stack_a, 1, 0);  // Highlight in green
    print_stack_color(stack_b, 1, 0);  // Highlight in green

    // N'oubliez pas de libérer la mémoire
    // ...

    return 0;
}

// gcc -I./includes test/test_swap.c src/swap.c -o test_swap