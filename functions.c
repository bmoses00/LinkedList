# include <stdio.h>
# include <stdlib.h>
# include "headers.h"

struct node * create_node(char newName[100], char newArtist[100] ) {
  struct node * head = calloc(208, 1);
  strncpy(head->name, newName);
  strncpy(head->artist, newArtist);
  head->next = NULL;
  return head;
}

void print_list(struct node * node) {
  printf("[");
  for ( ; node != NULL; node = node->next)
    printf("Name: %s, Artist: %s\n", node->name, node->artist);
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
    return head;
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

// not tested for edge cases (insert at end)
struct node * insert_in_order(struct node * node, int data) {
  if (node->i > data) return insert_front(node, data);

  struct node * head = node;
  for ( ; ; node = node->next) {
    if (node->next == NULL || node->next->i > data) {
      struct node * new = create_node(data);
      new->next = node->next;
      node->next = new;
      return head;
    }
  }
  return head;
}

struct node * return_node(struct node * node, int data) {
  for ( ; node != NULL; node = node->next)
    if (node->i == data)
      return node;
}
