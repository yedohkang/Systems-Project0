all: list.o playlist.o main.o
	gcc -o things list.o playlist.o main.o

list.o: list.c list.h
	gcc -c list.c

playlist.o: playlist.c playlist.h list.c list.h
	gcc -c playlist.c

main.o: main.c list.h playlist.h
	gcc -c main.c

clean:
	rm things
	rm *.o
	rm *~

run: all
	./things