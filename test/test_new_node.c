/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:00:25 by abouclie          #+#    #+#             */
/*   Updated: 2025/01/30 16:36:30 by abouclie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// Assurez-vous d'inclure les déclarations nécessaires pour t_stack et ft_atoi

// Fonction pour afficher le contenu de la pile
void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// Fonction pour libérer la mémoire de la pile
void free_stack(t_stack *stack) {
    t_stack *temp;
    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main(int argc, char **argv) {
    t_stack *stack_a = NULL;

    if (argc < 2) {
        printf("Usage: %s <number1> <number2> ...\n", argv[0]);
        return 1;
    }
	if (!is_correct_arg(argv))
		return (ft_putstr("Error\n"), 0);
    // Créer la pile à partir des arguments
    stack_creator(&stack_a, argv);

    // Afficher le contenu de la pile
    printf("Contenu de la pile : ");
    print_stack(stack_a);

    // Libérer la mémoire
    free_stack(stack_a);

    return 0;
}

// cc -I./includes test/test_new_node.c src/create_stack.c src/utils.c src/verif_input.c src/verif_input_utils.c