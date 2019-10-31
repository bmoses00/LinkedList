# include <stdio.h>
# include <stdlib.h>
# include "headers.h"
# include <string.h>

int main() {

  struct node * head = NULL;

  char name[100] = "Thriller";
  char artist[100] = "Michael Jackson";
  printf("Insert Thriller by Michael Jackson\n");
  head = insert_in_order(head, name, artist);

  strcpy(name, "Rocket Man");
  strcpy(artist, "Elton John");
  printf("Insert Rocket Man by Elton John\n");
  head = insert_in_order(head, name, artist);

  // strcpy(name, "Tiny Dancer");
  // strcpy(artist, "Elton John");
  // printf("Insert Tiny Dancer by Elton John\n");
  // head = insert_in_order(head, name, artist);

  print_list(head);

}
