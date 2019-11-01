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

  strcpy(name, "Tiny Dancer");
  strcpy(artist, "Elton John");
  printf("Insert Tiny Dancer by Elton John\n");
  head = insert_in_order(head, name, artist);

  strcpy(name, "Time");
  strcpy(artist, "Pink Floyd");
  printf("Insert Time by Pink Floyd\n");
  head = insert_in_order(head, name, artist);

  strcpy(name, "Stressed Out");
  strcpy(artist, "21 Pilots");
  printf("Insert Stressed Out by 21 Pilots\n");
  head = insert_in_order(head, name, artist);

  strcpy(name, "Numb");
  strcpy(artist, "Linkin Park");
  printf("Insert Numb by Linkin Park\n");
  head = insert_in_order(head, name, artist);

  print_list(head);

  // print_list(head);

  strcpy(name, "Stressed Out");
  strcpy(artist, "21 Pilots");

  head = remove_node(head, name, artist);

  print_list(head);

  printf("Freeing list\n");
  head = free_list(head);



}
