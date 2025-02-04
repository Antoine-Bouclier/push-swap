#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure du nœud
typedef struct s_node {
    int original_value;
    struct s_node *next;
} t_node;

// Prototype de la fonction normalize_values
void normalize_values(t_node *head);

// Fonction pour créer un nouveau nœud
t_node *create_node(int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) return NULL;
    new_node->original_value = value;
    new_node->next = NULL;
    return new_node;
}

// Fonction pour ajouter un nœud à la fin de la liste
void add_node(t_node **head, int value) {
    t_node *new_node = create_node(value);
    if (!*head) {
        *head = new_node;
    } else {
        t_node *current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Fonction pour afficher la liste
void print_list(t_node *head) {
    t_node *current = head;
    while (current) {
        printf("%d ", current->original_value);
        current = current->next;
    }
    printf("\n");
}

// Fonction pour libérer la mémoire de la liste
void free_list(t_node *head) {
    t_node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void normalize_values(t_node *head) {
    int min_value = INT_MAX;
    t_node *current = head;
    while (current) {
        if (current->original_value < min_value) {
            min_value = current->original_value;
        }
        current = current->next;
    }

    current = head;
    while (current) {
        current->original_value += abs(min_value);
        current = current->next;
    }
}

int main() {
    t_node *head = NULL;

    // Ajouter des éléments à la liste
    add_node(&head, 170);
    add_node(&head, -45);
    add_node(&head, 75);
    add_node(&head, -90);
    add_node(&head, 802);
    add_node(&head, 24);
    add_node(&head, -2);
    add_node(&head, 66);

    printf("Liste avant normalisation : ");
    print_list(head);

    // Normaliser les valeurs
    normalize_values(head);

    printf("Liste après normalisation : ");
    print_list(head);

    // Libérer la mémoire
    free_list(head);

    return 0;
}
