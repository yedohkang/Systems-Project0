// Ida + Yedoh
// Systems period 4
// Project 0: my_tunes
// 10/20/2017
// list.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a) {
  struct node * new = (struct node *)malloc(sizeof(struct node));

  strcpy(new->song, s);
  strcpy(new->artist, a);
  new->next = n;

  return new;
}

// insert song node in correct order
// returns head node
struct node * insert_ordered(struct node *n, char *s, char *a) {
  
  struct node * insert = (struct node *)malloc(sizeof(struct node));
  strcpy(insert->song, s);
  strcpy(insert->artist, a);
  insert->next = NULL;

  if (!n) {
    return insert;
  }
  
  if (strcmp(a, n->artist) < 0
     ||
     (strcmp(a, n->artist) == 0 && strcmp(s, n->song) < 0)) {
    insert->next = n;
    return insert;
  }
  
  struct node * head = n;
  struct node * before = (struct node *)malloc(sizeof(struct node));
  
  while (n && (strcmp(a, n->artist) > 0 ||
	      (strcmp(a, n->artist) == 0 && strcmp(s, n->song) > 0))) {
    before = n;
    n = n->next;
  }

  before->next = insert;
  insert->next = n;
  
  return head;
}

// print single node
void print_node(struct node *n) {
  printf("%s: %s\n", n->artist, n->song);
}

// print entire list
void print_list(struct node *head) {
  while (head) {
    print_node(head);
    head = head->next;
  }
  printf("\n");
}

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s, char *a) {
  while (n && (strcmp(n->artist, a) != 0 || strcmp(n->song, s) != 0)) {
    n = n->next;
  }
  if (n != NULL)
	  printf("Song found!\n");
  if (n == NULL)
	  printf("Song not found :(\n");
  return n;
}

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a) {
  while (n && strcmp(n->artist, a) != 0) {
    n = n->next;
  }
  if (n != NULL)
	  printf("Artist found!\n");
  if (n == NULL)
	  printf("Artist not found :(\n");
  return n;
}

// length
int length(struct node *n) {
  int len = 0;
  while (n) {
    len++;
    n = n->next;
  }
  return len;
}

int random_int(int range) {
  //srand(time(NULL));
  return rand() / (RAND_MAX / range + 1);
}

// pointer to random element in list
struct node * random_node(struct node *head) {
  int i = random_int(length(head));
  while (i) {
    head = head->next;
    i--;
  }
  return head;
}

// remove single node from the list
struct node * remove_node(struct node *head, struct node *n) {
  if (head == n) {
    head = head->next;
    free(n);
    return head;
  }
  struct node *hold = head;
  while (hold->next != n) {
    hold = hold->next;
  }
  if (!n->next) {
    hold->next = NULL;
    free(n);
  } else {
    hold->next = n->next;
    free(n);
  }
  return head;
}

// free entire list
struct node * free_list(struct node *n) {
  struct node * temp;
  while (n) {
    temp = n;
    n = n->next;
    free(temp);
  }
  return n;
}
