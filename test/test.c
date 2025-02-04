#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node {
    int original_value;  // Valeur originale
    int value;           // Valeur normalisée pour le tri
    int index;           // Index attribué à chaque valeur
    struct s_node *next;
} t_node;


// Fonction pour créer un nouveau nœud
t_node *create_node(int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node) return NULL;
    new_node->original_value = value;
    new_node->value = value;
    new_node->index = -1;
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

// Fonction pour libérer une liste chaînée
void free_list(t_node *head) {
    t_node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Fonction pour obtenir un digit à une position donnée
int get_digit(int number, int digit_position) {
    int divisor = 1;
    while (digit_position > 0) {
        divisor *= 10;
        digit_position--;
    }
    return (number / divisor) % 10;
}

// Fonction pour déterminer le nombre maximum de digits
int get_max_digits(t_node *head) {
    int max_number = INT_MIN;
    t_node *current = head;
    while (current) {
        if (current->value > max_number) {
            max_number = current->value;
        }
        current = current->next;
    }

    int digit_count = 0;
    while (max_number != 0) {
        max_number /= 10;
        digit_count++;
    }
    return digit_count;
}

// Fonction pour normaliser les valeurs (gestion des nombres négatifs)
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

// Fonction principale de Radix Sort
void radix_sort(t_node **head) {
    if (!*head) return;

    // Normaliser les valeurs pour gérer les nombres négatifs
    normalize_values(*head);

    // Trouver le nombre maximum de digits
    int max_digits = get_max_digits(*head);

    // Tableau de buckets pour chaque chiffre (0-9)
    t_node *buckets[10] = {NULL};
    t_node *output = NULL;

    // Trier pour chaque digit
    int digit_position = 0;
    while (digit_position < max_digits) {
        // Distribuer les éléments dans les buckets
        t_node *current = *head;
        while (current) {
            int digit = get_digit(current->original_value, digit_position);
            add_node(&buckets[digit], current->original_value);
            current = current->next;
        }

        // Reconstruire la liste à partir des buckets
        *head = NULL;
        int i = 0;
        while (i < 10) {
            t_node *bucket = buckets[i];
            while (bucket) {
                add_node(head, bucket->original_value);
                bucket = bucket->next;
            }
            free_list(buckets[i]); // Libérer le bucket après utilisation
            buckets[i] = NULL;
            i++;
        }

        digit_position++;
    }
}

// Fonction pour afficher la liste chaînée
void print_list(t_node *head) {
    t_node *current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

// Programme principal
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

    printf("Liste avant le tri : ");
    print_list(head);

    // Trier la liste avec Radix Sort
    radix_sort(&head);

    printf("Liste après le tri (normalisée): ");
    print_list(head);

    // Libérer la mémoire
    free_list(head);

    return 0;
}