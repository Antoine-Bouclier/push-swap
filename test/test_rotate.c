/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:31:23 by abouclie          #+#    #+#             */
/*   Updated: 2025/02/07 10:41:07 by abouclie         ###   ########.fr       */
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
    t_stack *current;
    int first_pass = 1;

    if (!stack)
    {
        printf("Stack is empty\n\n");
        return;
    }

    current = stack;
    while (current != stack || first_pass)
    {
        printf("Value: %d, Index: %d\n", current->value, current->index);
        current = current->next;
        first_pass = 0;
    }
    printf("\n");
}

void print_stack_color(t_stack *stack, int highlight_all, int before_operation)
{
    t_stack *current;
    int first_pass = 1;

    if (!stack)
    {
        printf("Stack is empty\n\n");
        return;
    }

    current = stack;
    while (current != stack || first_pass)
    {
        if (highlight_all)
        {
            if (before_operation)
                printf(YELLOW "Value: %d, Index: %d\n" RESET, current->value, current->index);
            else
                printf(GREEN "Value: %d, Index: %d\n" RESET, current->value, current->index);
        }
        else
            printf("Value: %d, Index: %d\n", current->value, current->index);
        
        current = current->next;
        first_pass = 0;
    }
    printf("\n");
}


int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    // Vérifier s'il y a suffisamment d'arguments
    if (argc < 2)
    {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    // Remplir stack_a avec les valeurs fournies
    stack_a = fill_stack_values(argc, argv);

    // Créer stack_b (vide pour l'instant)
    stack_b = NULL;

    // Test ra
    printf("Stack A before ra:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight all in yellow
    ra(&stack_a);
    printf("Stack A after ra:\n");
    print_stack_color(stack_a, 1, 0);  // Highlight all in green

    // Remplir stack_b avec quelques valeurs pour les tests
    int values_b[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++)
    {
        stack_add_bottom(&stack_b, stack_new(values_b[i]));
    }
    index_stack(stack_b);

    // Test rb
    printf("Stack B before rb:\n");
    print_stack_color(stack_b, 1, 1);  // Highlight all in yellow
    rb(&stack_b);
    printf("Stack B after rb:\n");
    print_stack_color(stack_b, 1, 0);  // Highlight all in green

    // Test rr
    printf("Stack A and B before rr:\n");
    print_stack_color(stack_a, 1, 1);  // Highlight all in yellow
    print_stack_color(stack_b, 1, 1);  // Highlight all in yellow
    rr(&stack_a, &stack_b);
    printf(RED "Stack A and B after rr:\n" RESET);
    print_stack_color(stack_a, 1, 0);  // Highlight all in green
    print_stack_color(stack_b, 1, 0);  // Highlight all in green

    return 0;
}


// gcc -I./includes test/test_rotate.c src/rotate.c src/utils.c -o test_rotate