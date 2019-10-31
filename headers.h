struct node {
  char name[100];
  char artist[100];
  struct node * next;
};

struct node * create_node(char newName[100], char newArtist[100]);
void print_list(struct node * node);
struct node * insert_front(struct node * node, char newName[100], char newArtist[100]);
struct node * free_list(struct node * head);
struct node * remove_node(struct node * front, char newName[100], char newArtist[100]);
struct node * insert_in_order(struct node * node, char newName[100], char newArtist[100]);
struct node * return_node(struct node * node, int data);
