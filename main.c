#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

#define BUFFER 255

typedef struct Game {
    char game_exe[BUFFER];
    char game_name[BUFFER];
} Game;

void parse_args(int *argc, char **argv, Game *game)
{
    int option;
    while ((option = getopt(*argc, argv, "e:")) != -1) {
      switch (option) {
          case 'e':
              strcpy(game->game_exe, optarg);
              /* printf("Given Path: %s\n", optarg); */
              break;
          case ':':
              printf("option needs a value\n");
              exit(EXIT_FAILURE);
              break;
          case '?':
              printf("unknown option: %c\n", optopt);
              exit(EXIT_FAILURE);
              break;
      }
    }
}

void get_game_name(Game *game)
{
    int n = 3;
    char tmp[255];
    strncpy(tmp, game->game_exe, strlen(game->game_exe) - n);
    tmp[strlen(tmp) - 1] = '\0';

    int index = 0;
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '/')
           index = i;
    }

    char *tmptmp = &tmp[index + 1];
    memcpy(game->game_name, tmptmp, n + 1);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("[ERROR]: Invalid usage\n[ERROR]: mainUsage: ./gamelauncher -e <exe>\n");
        exit(EXIT_FAILURE);
    }

    Game game;
    parse_args(&argc, argv, &game);
    get_game_name(&game);

    FILE *fp = fopen(game.game_name, "w");

    fprintf(fp, "#!/bin/env sh\n\n");

    for (int i = 0; i < EXTRA_ARGS_SIZE; i++) {
        fprintf(fp, "export %s\n", extra_args[i]);
    }

    fprintf(fp, "\n");

    fprintf(fp, "cd %s\n\n", CD_PATH);

    fprintf(fp,"%s run '%s'", PROTON_PATH, game.game_exe);

    fclose(fp);

    char cmd[255] = "chmod u+x ";
    strncat(cmd, game.game_name, strlen(game.game_name));
    printf("%s\n", cmd);
    system(cmd);

    return 0;
}
