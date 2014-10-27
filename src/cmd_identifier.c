//
//      Tomas Petras Rupsys
//

#include "cmd_identifier.h"

AppCommand identifyCommand(char *input) {

  if (strcmp(input, "exit") == 0) {
    return EXIT;

  } else if (strcmp(input, "help") == 0) {
    return HELP;

  } else if (strncmp(input, "fg", 2) == 0) {
    return FOREGROUND;

  } else if (strncmp(input, "bg", 2) == 0) {
    return BACKGROUND;

  } else if (strcmp(input, "jobs") == 0) {
    return JOBS;

  } else if (strncmp(input, "kill", 4) == 0) {
    return KILL;

  } else if (strstr(input, "&") != NULL && strlen(input) > 2) {
    return NEW_BG;

  } else {
    return NEW_FG;
  }
}

// FIXME: possible memory leak with this implementation
char *trim(char *data) {

  int i = strlen(data) - 1;

  // Right trim
  while (isspace(data[i])) {
    data[i--] = '\0';
  }

  // Left trim
  while (isspace(*data)) {
    data++;
  }

  return data;
}

int parseFgArgs(char *rawInput) {

  // Handling invalid input
  if (strlen(trim(rawInput)) == 2) {
    printf("Usage: fg [job number]\n\n");
    return INVALID_INT_ARG;
  }

  // Taking the number out of command and parsing an integer
  char arg[INPUT_SIZE];

  int i;
  int j;
  for (i=3,j=0 ; i<strlen(rawInput) ; i++,j++) {
    arg[j] = rawInput[i];
  }

  int fgArgument = atoi(arg);
  return fgArgument;
}

int parseBgArgs(char *rawInput) {

  // Handling invalid input
  if (strlen(trim(rawInput)) == 2) {
    printf("Usage: bg [job number]\n\n");
    return INVALID_INT_ARG;
  }

  // Taking the number out of command and parsing an integer
  char arg[INPUT_SIZE];

  int i;
  int j;
  for (i=3,j=0 ; i<strlen(rawInput) ; i++,j++) {
    arg[j] = rawInput[i];
  }

  return atoi(arg);
}

int parseKillArgs(char *rawInput) {

  // Handling invalid input
  if (strlen(trim(rawInput)) == 2) {
    printf("Usage: kill [job number]\n\n");
    return INVALID_INT_ARG;
  }

  // Taking the number out of command and parsing an integer
  char arg[INPUT_SIZE];

  int i;
  int j;
  for (i=5,j=0 ; i<strlen(rawInput) ; i++,j++) {
    arg[j] = rawInput[i];
  }

  return atoi(arg);
}

char *parseNewBgProcessesArgs(char *rawInput) {

  // Handling invalid input
  if (strcmp("&", trim(rawInput)) == 0) {
    printf("Usage: [unix command] &\n");
    return INVALID_STR_ARG;
  }

  // Removing '&' sign and trimming the whitespace
  char processString[INPUT_SIZE];
  strcpy(processString, trim(rawInput));
  processString[strlen(processString) - 1] = 0;
  return trim(processString);
}

char *parseNewFgProcessesArgs(char *rawInput) {

  // Trimming the whitespace
  return trim(rawInput);
}
