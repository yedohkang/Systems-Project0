// Ida + Yedoh
// Systems period 4
// Project 0: my_tunes
// 10/20/2017
// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"
#include "playlist.h"

int main(){
  srand(time(NULL));
	
  printf("\n\ntesting my_tunes!!!");

  printf("TESTING FOR LIST FUNCTIONS========================\n\n");

  printf("print_node----------------------------------------\n");
  printf("--> creating and printing original node formatted artist: song\n");
  struct node * head = (struct node *)malloc(sizeof(struct node));
  strcpy(head->song, "sweet caroline");
  strcpy(head->artist, "neil diamond");
  print_node(head);
  printf("\n");
  
  printf("insert_ordered------------------------------------\n");
  printf("-->  inserting chandelier then hallelujah\n");
  head = insert_ordered(head, "chandelier", "sia");
  head = insert_ordered(head, "hallelujah", "pentatonix");
  print_list(head);

  printf("insert_front--------------------------------------\n");
  printf("-->  inserting rolling in the deep\n");
  head = insert_front(head, "rolling in the deep", "adele");
  print_list(head);

  printf("find_song-----------------------------------------\n");
  printf("-->  finding chandelier\n");
  struct node * find = find_song(head, "chandelier", "sia");
  print_list(find);
	
  printf("find_song-----------------------------------------\n");
  printf("-->  riptide\n");
  struct node * find1 = find_song(head, "riptide", "vance joy");
  print_list(find1);

  printf("find_artist---------------------------------------\n");
  printf("-->  finding neil diamond\n");
  find = find_artist(head, "neil diamond");
  print_list(find);
	
  printf("find_artist---------------------------------------\n");
  printf("-->  finding vance joy\n");
 	struct node * find2 = find_artist(head, "vance joy");
  print_list(find2);

  printf("length--------------------------------------------\n");
  printf("length of list: %d\n\n", length(head));
  
  printf("print_list----------------------------------------\n");
  print_list(head);

  printf("random_node---------------------------------------\n");
  struct node * random = random_node(head);
  print_list(random);

  printf("remove_node---------------------------------------\n");
  printf("-->  removing random node given above\n");
  head = remove_node(head, random);
  print_list(head);

  printf("random_int----------------------------------------\n");
  printf("-->  printing series of random integers from 0 to 25\n");
  for(int i = 0; i < 10; i++){
    printf("%d  ", random_int(26));
  }
  printf("\n\n");

  printf("free_list-----------------------------------------\n");
  head = free_list(head);
  print_list(head);
  printf("printed list after freeing\n\n");

  printf("\nTESTING PLAYLIST FUNCTIONS=======================\n\n");

  struct node * thing[26];
  for(int i = 0; i < 26; i++){
    thing[i] = NULL;
  }
  
  printf("add-----------------------------------------------\n");
  printf("-->  adding rolling in the deep, galway girl, hello, just give me a reason, hallelujah\n");
  add(thing, "rolling in the deep", "adele");
  add(thing, "galway girl", "ed sheeran");
  add(thing, "hello", "adele");
  add(thing, "just give me a reason", "pink");
  add(thing, "hallelujah", "pentatonix");
  print_all(thing);
  
  printf("search song---------------------------------------\n");
  printf("-->  galway girl by ed sheeran \n");
  struct node * search = search_song(thing, "ed sheeran", "galway girl");
  print_list(search);

  printf("search_artist-------------------------------------\n");
  printf("-->  searching for pentatonix\n");
  print_list(search_artist(thing, "pentatonix"));
  
  printf("print_letter--------------------------------------\n");
  printf("-->  printing entries under p\n");
  print_letter(thing, 'p');

  printf("print_artist--------------------------------------\n");
  printf("-->  printing out all of adele's songs\n");
  print_artist(thing, "adele");

  printf("delete_song---------------------------------------\n");
  printf("-->  deleting adele: hello\n");
  delete_song(thing, "adele", "hello");
  print_all(thing);
  
  printf("shuffle-------------------------------------------\n");
  shuffle(thing);

  printf("delete_all----------------------------------------\n");
  delete_all(thing);
  print_all(thing);
  printf("finished deleting all and printed library\n\n");
}
