#include <stddef.h>

typedef struct node {
  int value;
  struct node *next;
  struct node *prev;
} node_t;

node_t *create_node(int value, node_t *previous);
node_t *create_list(int *values, size_t length);
void reverse_list(node_t *head);
