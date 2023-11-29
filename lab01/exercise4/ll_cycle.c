#include <stddef.h>
#include "ll_cycle.h"
#include <stdbool.h>
int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    if (head == NULL) {
        return false; // An empty list cannot have a cycle.
    }

    node *fast_ptr = head;
    node *slow_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next; // Advance fast_ptr by two nodes
        slow_ptr = slow_ptr->next;       // Advance slow_ptr by one node

        if (fast_ptr == slow_ptr) {
            return true; // fast_ptr and slow_ptr have met, indicating a cycle
        }
    }

    return false; // Reached the end of the list, no cycle found
}
