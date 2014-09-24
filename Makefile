CC=gcc
CFLAGS=-Wall -pedantic -std=c99


all: program


%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@


program: tris.o data.o utilisation.o
	$(CC) $^ -o $@


tris.o: tris.c tris.h
data.o: data.c data.h
utilisation.o: utilisation.c tris.h data.h




##	##
# CLEAN	 #
##	##
clean:
	rm -rf *.o *~ program






