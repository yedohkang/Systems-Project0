// Ida + Yedoh
// Systems period 4
// Project 0: my_tunes
// 10/20/2017
// playlist.h

// add songs
void add(struct node *library[26], char *s, char *a);

// search for a song
struct node * search_song(struct node *library[26], char *a, char *s);

// search for an artist
struct node * search_artist(struct node *library[26], char *a);

// print out all entries under certain letter
void print_letter(struct node *library[26], char l);

// print out all songs of certain artist
void print_artist(struct node *library[26], char *a);

// print entire library
void print_all(struct node *library[26]);

// returns length of playlist
int length_playlist(struct node * library[26]);

// print out series of randomly chosen songs
void shuffle(struct node *library[26]);

// delete a song
void delete_song(struct node *library[26], char *a, char *s);

// delete all
void delete_all(struct node *library[26]);
