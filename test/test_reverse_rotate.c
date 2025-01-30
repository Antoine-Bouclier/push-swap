/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:20:47 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 09:26:52 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
void print_stack_color(t_stack *stack, int highlight_all, int before_operation)
{
    while (stack)
    {
        if (highlight_all)
        {
            if (before_operation)
                printf(YELLOW "Value: %d, Index: %d\n" RESET, stack->value, stack->index);
            else
                printf(GREEN "Value: %d, Index: %d\n" RESET, stack->value, stack->index);
        }
        else
            printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("\n");
}

int main()
{
    // Test ra
    int values_a[] = {1, 2, 3, 4, 5};
    t_stack *stack_a = create_stack(values_a, 5);
    printf("Stack A before rra:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight all in yellow
    rra(&stack_a);
    printf("Stack A after rra:\n");
    print_stack_color(stack_a, 1, 0);  // Highlight all in green

    // Test rb
    int values_b[] = {10, 20, 30, 40, 50};
    t_stack *stack_b = create_stack(values_b, 5);
    printf("Stack B before rrb:\n");
    print_stack_color(stack_b, 1, 1);  // Highlight all in yellow
    rrb(&stack_b);
    printf("Stack B after rrb:\n");
    print_stack_color(stack_b, 1, 0);  // Highlight all in green

    // Test rr
    printf("Stack A and B before rrr:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight all in yellow
    print_stack_color(stack_b, 1, 1);  // Highlight all in yellow
    rrr(&stack_a, &stack_b);
    printf(RED "Stack A and B after rrr:\n" RESET);
    print_stack_color(stack_a, 1, 0);  // Highlight all in green
    print_stack_color(stack_b, 1, 0);  // Highlight all in green

    // N'oubliez pas de libérer la mémoire
    // ...

    return 0;
}

// gcc -I./includes test/test_rotate.c src/reverse_rotate.c src/utils.c -o test_reverse_rotate