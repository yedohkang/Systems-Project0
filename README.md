# Project 0: my_tunez
A music library organizer thing. Project outline for convenience.

### Basic Structure
An array of 26 slots ('a' -> 'z').
Each slot contains a linked list of all the songs by artists of that corresponding letter.
Each node holds a song title and artist.

### Linked List Functions
- insert nodes in front
- print out entire list
- find and return a pointer to a song based on name
- find and return a pointer to the first song of an artist based on name
- return a pointer to a random element in the list
- remove a single node from the list
- free the entire list

### Full Program Functions
- add songs
- search for songs
- search for artists
- print out all entries under a certain letter (linked list associated with a certain array slot)
- print out all songs from a certain artist
- print out entire library
- shuffle - print out a series of randomly chosen songs
- delete a song
- delete all the nodes

### Files That are Probably Important to Have
- main.c to test work (**must have all functions tested for full credit!!!**)
- at least one set of .h/.c files (i.e. separate sets for playlist specific functions, and linked list functions, .h file for struct and linked list headers, etc.) 
- makefile that will generate one single executeable program