struct node {
  int i;
  struct node * next;
};

struct node * create_node(int data);
void print_list(struct node * node);
struct node * insert_front(struct node * node, int data);
struct node * free_list(struct node * head);
struct node * remove_node(struct node * front, int data);
