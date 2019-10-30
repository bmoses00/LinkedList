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

  printf("Insert 50\n");
  head = insert_in_order(head, 50);

  printf("Insert 20\n");
  head = insert_in_order(head, 20);

  printf("Insert 0\n");
  head = insert_in_order(head, 0);

  printf("Insert 2\n");
  head = insert_in_order(head, 2);

  printf("Printing list:\n");
  print_list(head);

  printf("Returning 20:\n");
  printf("%d\n", return_node(head, 20)->i);

  printf("Returning 36\n");
  printf("%d\n", return_node(head, 36)->i);
}
