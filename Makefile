CC=gcc
CFLAGS=-g0 -O3 -Wall

BINS=app libdlinkedlist.so runtime_libapp

all: $(BINS)

app: app.c dlinked_list.o
	$(CC) $(CFLAGS) -o $@ $^

libdlinkedlist.so: dlinked_list.c dlinked_list.h
	$(CC) $(CFLAGS) -shared -fPIC -o $@ dlinked_list.c

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

runtime_libapp: app.c
	$(CC) $(CFLAGS) -o $@ $^  -L. -ldlinkedlist

clean:
	rm -f $(BINS) *.o
