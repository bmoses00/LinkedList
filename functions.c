# include <stdio.h>
# include <stdlib.h>
# include "headers.h"
# include <string.h>
# include <time.h>

struct node * create_node(char newName[100], char newArtist[100] ) {
  struct node * head = calloc(208, 1);
  strcpy(head->name, newName);
  strcpy(head->artist, newArtist);
  head->next = NULL;
  return head;
}

void print_list(struct node * node) {
  printf("LinkedList:\n");
  for ( ; node != NULL; node = node->next)
    printf("Name: %s, Artist: %s\n", node->name, node->artist);
  printf("\n\n");
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

  if (strcmp(front->name, newName) == 0 && strcmp(front->artist, newArtist) == 0) {
    struct node * returnNode = front->next;
    free(front);
    return returnNode;
  }
  struct node * node = front;
  for ( ; node->next != NULL; node = node->next) {
    if (strcmp(node->next->name, newName) == 0 && strcmp(node->next->artist, newArtist) == 0) {
      struct node * nodeToFree = node->next;
      node->next = node->next->next;
      free(nodeToFree);
      return front;
    }
  }
  return front;

}

struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]) {
  if (node == NULL) return insert_front(node, newName, newArtist);

  if (node->next == NULL
    ||
      (strcmp(node->next->artist, newArtist) >= 0
    && strcmp(node->next->name, newName) >= 0))
    return insert_front(node, newName, newArtist);


  struct node * head = node;
  for ( ; ; node = node->next) {

    if (
      node->next == NULL
      ||
        strcmp(node->next->artist, newArtist) > 0
    || (strcmp(node->next->artist, newArtist) == 0 && strcmp(node->next->name, newName) >= 0)) {

      struct node * new = create_node(newName, newArtist);
      new->next = node->next;
      node->next = new;
      return head;

    }
  }
  return head;
}

struct node * return_song(struct node * node, char newName[100], char newArtist[100]) {
  for ( ; node != NULL; node = node->next)
    if (strcmp(node->name, newName) == 0 && strcmp(node->artist, newArtist) == 0)
      return node;
}

struct node * return_first_of_artist(struct node * node, char newArtist[100]) {
  for ( ; node != NULL; node = node->next)
    if (strcmp(node->artist, newArtist) == 0)
      return node;
}

struct node * return_random(struct node * node) {
  int length;
  for (length = 0; node != NULL; node = node->next, length += 1) {}
  srand(time(NULL));
  int desiredNode = rand() % length;

  int counter;
  for (counter = 0; counter == desiredNode; node = node->next, counter += 1) {}
  return node;
}
