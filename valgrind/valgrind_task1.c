// Credit: https://github.com/wwu-mentors
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

node_t* make_list(int argc, char *argv[]) {
  node_t* linked_list = NULL;
  node_t* current_node = NULL;

  for(int i = 1 ; i < argc ; ++i) {
    if(linked_list == NULL){
      linked_list = new_node(strdup(argv[i]));
      current_node = linked_list;
    } else {
      current_node->next = new_node(strdup(argv[i]));
      current_node = current_node->next;
    }
  }
  return linked_list;
}

#ifdef TASK2
void free_list(node_t *list) {
  while(NULL != list) {
    free(list->data);
    delete_node(list);
    list = list->next;
  }
}
#else
void free_list(node_t *list) {
  node_t *current_node;
  while(list != NULL) {
    current_node = list;
    list = list->next;
    delete_node(current_node);
  }
}
#endif

int print_args(int argc, char *argv[]) {
  node_t* linked_list = NULL;
  node_t* current_node = NULL;

  linked_list = make_list(argc, argv);

  current_node = linked_list;
  while(current_node != NULL) {
    printf("%s\n", (char *) current_node->data);
    current_node = current_node->next;
  }
  free_list(linked_list);
#ifdef TASK2
  if (linked_list != NULL)
    return EXIT_FAILURE;
#endif
  return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
  return print_args(argc, argv);
}
