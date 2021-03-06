//
//      Tomas Petras Rupsys
//

#ifndef cmd_identifier_H
#define cmd_identifier_H

#define INVALID_INT_ARG -1
#define INVALID_STR_ARG "INVALID_STRING"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "model/app_command.h"
#include "app.h"
#include "shell.h"

/* Trims the whitespace from sides */
char *trim(char *data);

/* Identifier what kind of application command is the given input */
AppCommand identifyCommand(char *input);

/* Parses an argument required for foreground command */
int parseFgArgs(char *rawInput);

/* Parses an argument required for background command */
int parseBgArgs(char *rawInput);

/* Parses an argument required for kill command */
int parseKillArgs(char *rawInput);

/* Parses a string of process to be created in background */
char *parseNewBgProcessesArgs(char *rawInput);

/* Parses a string of process to be created in foreground */
char *parseNewFgProcessesArgs(char *rawInput);

#endif
