# include <stdio.h>
# include <stdlib.h>
# include "headers.h"
# include <string.h>

struct node * create_node(char newName[100], char newArtist[100] ) {
  struct node * head = calloc(208, 1);
  strcpy(head->name, newName);
  strcpy(head->artist, newArtist);
  head->next = NULL;
  return head;
}

void print_list(struct node * node) {
  printf("[");
  for ( ; node != NULL; node = node->next)
    printf("Name: %s, Artist: %s\n", node->name, node->artist);
  printf("]\n");
}

struct node * insert_front(struct node * node, char newName[100], char newArtist[100]) {
  struct node * newHead = create_node(newName, newArtist);
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

struct node * remove_node(struct node * front, char newName[100], char newArtist[100]) {
  // if (front->i == data) {
  //   struct node * returnNode = front->next;
  //   free(front);
  //   return returnNode;
  // }
  // struct node * node = front;
  // for ( ; node->next != NULL; node = node->next) {
  //   if (node->next->i == data) {
  //     struct node * nodeToFree = node->next;
  //     node->next = node->next->next;
  //     free(nodeToFree);
  //     return front;
  //   }
  // }
  // return front;
}

struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]) {
  if (node == NULL) return insert_front(node, newName, newArtist);

  char nameAndArtist[200];
  strcpy(nameAndArtist, strcat(newArtist, newName));

  char nodeNameAndArtist[200];
  strcpy(nodeNameAndArtist, strcat(node->artist, node->name));

  printf("%s\n", nameAndArtist);
  if (strcmp(nodeNameAndArtist, nameAndArtist) >= 0)
    return insert_front(node, newName, newArtist);

  struct node * head = node;
  for ( ; ; node = node->next) {
    strcpy(nodeNameAndArtist, strcat(node->next->artist, node->next->name));
    if (node->next == NULL || strcmp(nodeNameAndArtist, nameAndArtist) > 0) {
      struct node * new = create_node(newName, newArtist);
      new->next = node->next;
      node->next = new;
      return head;
    }
  }
  return head;
}

struct node * return_node(struct node * node, int data) {
  // for ( ; node != NULL; node = node->next)
  //   if (node->i == data)
  //     return node;
}
