// Credit: https://github.com/wwu-mentors
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

node_t* new_node(void *data) {
  node_t *new = (node_t *) malloc(sizeof(node_t));
  assert(NULL != new);
  new->next = NULL;
  new->data = data;
  return new;
}

void delete_node(node_t *node) {
  free(node);
}
