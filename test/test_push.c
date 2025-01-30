/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:39:31 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 09:27:13 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
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

void print_stack_color(t_stack *stack, const char* name, int highlight_first)
{
    printf("%s:\n", name);
    int count = 0;
    while (stack)
    {
        if (count == 0 && highlight_first)
            printf(GREEN "Value: %d, Index: %d\n" RESET, stack->value, stack->index);
        else
            printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
        count++;
    }
    printf("\n");
}

int main()
{
    // Initialisation des stacks
    int values_a[] = {1, 2, 3, 4, 5};
    int values_b[] = {10, 20, 30, 40, 50};
    t_stack *stack_a = create_stack(values_a, 5);
    t_stack *stack_b = create_stack(values_b, 5);

    // Affichage initial
    printf(YELLOW "Initial state:\n" RESET);
    print_stack_color(stack_a, "Stack A", 0);
    print_stack_color(stack_b, "Stack B", 0);

    // Test pa
    printf(BLUE "Testing pa (push from B to A):\n" RESET);
    pa(&stack_a, &stack_b);
    print_stack_color(stack_a, "Stack A after pa", 1);
    print_stack_color(stack_b, "Stack B after pa", 0);

    // Test pb
    printf(BLUE "Testing pb (push from A to B):\n" RESET);
    pb(&stack_b, &stack_a);
    print_stack_color(stack_a, "Stack A after pb", 0);
    print_stack_color(stack_b, "Stack B after pb", 1);

    // Test multiple operations
    printf(RED "Testing multiple operations:\n" RESET);
    pa(&stack_a, &stack_b);
    pa(&stack_a, &stack_b);
    pb(&stack_b, &stack_a);
    print_stack_color(stack_a, "Final Stack A", 1);
    print_stack_color(stack_b, "Final Stack B", 1);

    // N'oubliez pas de libérer la mémoire
    // ...

    return 0;
}

// gcc -I./includes test/test_push.c src/push.c src/utils.c -o test_push