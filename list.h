// Ida + Yedoh
// Systems period 4
// Project 0: my_tunes
// 10/20/2017
// list.h

struct node {
  char song[256];
  char artist[256];
  struct node *next;
};

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a);

struct node * insert_ordered(struct node *n, char *s, char *a);

void print_node(struct node *n);

// print entire list
void print_list(struct node *head);

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s, char *a);

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a);

// length of linked list
int length(struct node *n);

// pointer to random element in list
struct node * random_node(struct node *head);

// remove single node from the list
struct node * remove_node(struct node *head, struct node *n);

// free entire list
struct node * free_list(struct node *n);

int random_int(int range);
