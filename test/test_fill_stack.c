#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_stack(t_stack *stack) {
    if (!stack) {
        printf("La pile est vide.\n");
        return;
    }
    
    t_stack *current = stack;
    int count = 0;
    do {
        printf("Node %d: Value: %d, Index: %d\n", count, current->value, current->index);
        printf("  Current: %p, Next: %p, Precedent: %p\n", 
               (void*)current, (void*)current->next, (void*)current->precedent);
        current = current->next;
        count++;
    } while (current != stack);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <nombre1> <nombre2> ...\n", argv[0]);
        return 1;
    }

    t_stack *stack_a = fill_stack_values(argc, argv);

    printf("Pile initiale :\n");
    print_stack(stack_a);

    return 0;
}
