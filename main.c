# include <stdio.h>
# include <stdlib.h>
# include "headers.h"

int main() {
  printf("Printing empty list: ");
  print_list(NULL);
  printf("Creating list [5, 10, 15, 20, 25, 30]\n");
  int i;
  struct node * head = NULL;
  for (i = 6; i > 0; i--)
    head = insert_front(head, i * 5);
  printf("Printing list:\n");
  print_list(head);

  printf("Remove 25:\n");
  head = remove_node(head, 25);
  print_list(head);

  printf("Remove 0:\n");
  head = remove_node(head, 0);
  print_list(head);

  printf("Remove 10:\n");
  head = remove_node(head, 10);
  print_list(head);

  printf("Remove -50:\n");
  head = remove_node(head, 10);
  print_list(head);

  printf("Insert 25\n");
  head = insert_in_order(head, 25);
  // printf("Free list\n");
  // head = free_list(head);
  printf("Printing list:\n");
  print_list(head);
}
