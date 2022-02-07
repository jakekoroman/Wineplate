##
# Game Launcher
#
# @file
# @version 0.1

CFLAGS=-std=c11 -Wall -pedantic
LDFLAGS=

gamelauncher: main.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o gamelauncher main.c

clean:
	rm -f gamelauncher

# end
