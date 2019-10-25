# include <stdio.h>
# include <stdlib.h>
# include "headers.h"

struct node * create_node(int data) {
  struct node * head = calloc(16, 1);
  head->i = data;
  head->next = NULL;
  return head;
}

void print_list(struct node * node) {
  printf("[");
  for ( ; node != NULL; node = node->next)
    printf("%d,", node->i);
  printf("]\n");
}

struct node * insert_front(struct node * node, int data) {
  struct node * newHead = create_node(data);
  newHead->next = node;
  return newHead;
}

struct node * free_list(struct node * head) {
  if (head != NULL) {
    free_list(head->next);
    free(head);
  }
  else
    return NULL;
}

struct node * remove_node(struct node * front, int data) {
  if (front->i == data) {
    struct node * returnNode = front->next;
    free(front);
    return returnNode;
  }

  struct node * node = front;
  for ( ; node->next != NULL; node = node->next) {
    if (node->next->i == data) {
      struct node * nodeToFree = node->next;
      node->next = node->next->next;
      free(nodeToFree);
      return front;
    }
  }
  return front;
}
