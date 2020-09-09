P=parser
OBJECTS=main.o argparse.o
CC=gcc
CFLAGS=-Wall


$(P): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(P) $(OBJECTS)

.PHONY: clean
clean:
	rm $(OBJECTS) $(P)

