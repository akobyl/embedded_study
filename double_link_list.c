#include "double_link_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node_t *create_node(int value, node_t *previous) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  new_node->prev = previous;

  if (previous != NULL) {
    previous->next = new_node;
  }

  return new_node;
}

node_t *create_list(int *values, size_t length) {
  if (length == 0) {
    return NULL;
  }

  node_t *head = create_node(values[0], NULL);
  node_t *current = head;

  for (size_t i = 1; i < length; i++) {
    node_t *next = create_node(values[i], current);
    current = next;
  }

  return head;
}

void reverse_list(node_t *head) {
    node_t *current = head;
    node_t *temp = NULL;

    while (current != NULL) {
        // Swap the next and prev pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }

    // If the list is not empty, set the new head
    if (temp != NULL) {
        head = temp->prev;
    }
}
