/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_biggest_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:52:36 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 17:58:04 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// Déclaration de vos fonctions
t_stack *get_biggest(t_stack *stack_a);
void add_node(t_stack **stack, int value);
void free_stack(t_stack *stack);

int main(int argc, char **argv) {
    t_stack *stack = NULL;
    t_stack *biggest;
    int i;

    if (argc < 2) {
        printf("Usage: %s <nombre1> <nombre2> ...\n", argv[0]);
        return 1;
    }

    // Création de la pile à partir des arguments
    for (i = 1; i < argc; i++) {
        add_node(&stack, atoi(argv[i]));
    }

    // Trouver le plus grand nombre
    biggest = get_biggest(stack);

    if (biggest) {
        printf("Le plus grand nombre est : %d\n", biggest->value);
    } else {
        printf("La pile est vide.\n");
    }

    // Libération de la mémoire
    free_stack(stack);

    return 0;
}

// Implémentation de add_node (si ce n'est pas déjà fait ailleurs)
void add_node(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    new_node->value = value;
    new_node->next = NULL;

    if (*stack == NULL) {
        *stack = new_node;
    } else {
        t_stack *current = *stack;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Implémentation de free_stack (si ce n'est pas déjà fait ailleurs)
void free_stack(t_stack *stack) {
    while (stack != NULL) {
        t_stack *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

