CFLAGS=-std=c11 -Wall -pedantic
LDFLAGS=

wineplate: main.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) 

debug: main.c
	$(CC) $(CFLAGS) -g -o $@ $< $(LDFLAGS)

clean:
	rm -f wineplate debug
