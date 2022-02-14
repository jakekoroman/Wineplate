#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

#define BUFFER 1024 

typedef struct Game {
    char *game_exe;
    char *game_name;
    char *game_output_file;
} Game;

void parse_args(int *argc, char **argv, Game *game)
{
    int option;
    while ((option = getopt(*argc, argv, ":e:")) != -1) {
        switch (option) {
            case 'e':
                //strncpy(game->game_exe, optarg, strlen(optarg));
                game->game_exe = optarg;
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

// functions set game->game_name to just the game's name removing the full path and the .exe 
// Example: game->game_exe = /home/user/program.exe -> game->game_name = program
void get_game_name(Game *game)
{
    int n = 3;
    char tmp[strlen(game->game_exe)];
    strncpy(tmp, game->game_exe, strlen(game->game_exe) - n);   // trims the exe off the end
    tmp[strlen(tmp) - 1] = '\0';                                // sets the . to \0

    int index = 0;
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '/')                                      // finds the index of the last /
           index = i;
    }

    if (index >= 0) {
        char *tmptmp = &tmp[index + 1];                         // create a new string that starts at 1 char after the last /
        game->game_name = malloc(sizeof(tmptmp));
        strncpy(game->game_name, tmptmp, strlen(tmptmp));
    } else {
        strncpy(game->game_name, tmp, strlen(tmp));              // if there are no /'s then just memcpy tmp
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("[ERROR]: Invalid usage\n[ERROR]: Main Usage: ./gamelauncher -e <exe>\n");
        exit(EXIT_FAILURE);
    }

    Game game;
    parse_args(&argc, argv, &game);
    get_game_name(&game);

    game.game_output_file = malloc(sizeof(game.game_name) + 6);
    sprintf(game.game_output_file, "games/%s", game.game_name);

    FILE *fp = fopen(game.game_output_file, "w");

    fprintf(fp, "#!/bin/env sh\n\n");

    for (int i = 0; i < EXTRA_ARGS_SIZE; i++) {
        fprintf(fp, "export %s\n", extra_args[i]);
    }

    fprintf(fp, "\n");
    fprintf(fp, "cd %s\n\n",   CD_PATH);
    fprintf(fp, "%s run '%s'", PROTON_PATH, game.game_exe);

    fclose(fp);

    printf("[INFO] Created file %s successfully!\n", game.game_output_file);

    char cmd[BUFFER] = "chmod u+x ";
    strncat(cmd, game.game_output_file, strlen(game.game_output_file));
    printf("[CMD]  %s\n", cmd);
    system(cmd);

    printf("[INFO] Game script created successfully!\n");

    free(game.game_name);
    free(game.game_output_file);

    return 0;
}
