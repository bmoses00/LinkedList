# include <stdio.h>
# include <stdlib.h>
# include "headers.h"

int main() {
  printf("Printing empty list: ");
  print_list(NULL);
  printf("Creating list [25, 20, 15, 10, 5, 0, -5]\n");
  struct node * head = create_node(0);
  int i;
  for (i = 1; i < 6; i++)
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

  printf("Free list\n");
  head = free_list(head);
  // printf("Printing list:\n");
  // print_list(head);
}
