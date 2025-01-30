/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_max_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:40:33 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 18:44:05 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Déclarations de vos fonctions
t_stack *get_biggest(t_stack *stack_a);
int get_max_digits(t_stack *stack);

// Fonction auxiliaire pour ajouter un nœud à la pile
void add_node(t_stack **stack, int value) {
    t_stack *new_node = malloc(sizeof(t_stack));
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Fonction auxiliaire pour libérer la mémoire de la pile
void free_stack(t_stack *stack) {
    while (stack) {
        t_stack *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main() {
    t_stack *stack = NULL;
    int digits;

    // Test 1: Pile vide
    assert(get_biggest(stack) == NULL);
    digits = get_max_digits(stack);
    printf("Test 1: Pile vide - Nombre de digits: %d\n", digits);

    // Test 2: Un seul élément
    add_node(&stack, 5);
    assert(get_biggest(stack)->value == 5);
    digits = get_max_digits(stack);
    printf("Test 2: Un seul élément (5) - Nombre de digits: %d\n", digits);

    // Test 3: Plusieurs éléments, le plus grand à un chiffre
    add_node(&stack, 3);
    add_node(&stack, 7);
    add_node(&stack, 1);
    assert(get_biggest(stack)->value == 7);
    digits = get_max_digits(stack);
    printf("Test 3: Plusieurs éléments (7, 3, 5, 1) - Nombre de digits: %d\n", digits);

    // Test 4: Le plus grand à deux chiffres
    add_node(&stack, 42);
    assert(get_biggest(stack)->value == 42);
    digits = get_max_digits(stack);
    printf("Test 4: Ajout de 42 - Nombre de digits: %d\n", digits);

    // Test 5: Le plus grand à trois chiffres
    add_node(&stack, 999);
    assert(get_biggest(stack)->value == 999);
    digits = get_max_digits(stack);
    printf("Test 5: Ajout de 999 - Nombre de digits: %d\n", digits);

    // Test 6: Ajout d'un nombre à quatre chiffres
    add_node(&stack, 1000);
    assert(get_biggest(stack)->value == 1000);
    digits = get_max_digits(stack);
    printf("Test 6: Ajout de 1000 - Nombre de digits: %d\n", digits);

    // Libération de la mémoire
    free_stack(stack);
    return 0;
}
