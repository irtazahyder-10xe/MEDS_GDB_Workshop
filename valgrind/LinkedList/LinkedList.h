// Credit: https://github.com/wwu-mentors
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
typedef struct node {
  void *data;
  void *next;
} node_t;

node_t* new_node(void *data);
void delete_node(node_t *node);
#endif /*_LINKEDLIST_H_*/
