##
# Game Launcher
#
# @file
# @version 0.1

CFLAGS=-std=c11 -Wall -pedantic
LDFLAGS=

gamelauncher: main.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) 

debug: main.c
	$(CC) $(CFLAGS) -g -o $@ $< $(LDFLAGS)

clean:
	rm -f gamelauncher debug

# end
