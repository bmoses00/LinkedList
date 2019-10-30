struct node {
  char name[100];
  char artist[100];
  struct node * next;
};

struct node * create_node(int data);
void print_list(struct node * node);
struct node * insert_front(struct node * node, int data);
struct node * free_list(struct node * head);
struct node * remove_node(struct node * front, int data);
struct node * insert_in_order(struct node * node, int data);
struct node * return_node(struct node * node, int data);
