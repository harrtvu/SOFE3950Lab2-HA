#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#define BUFSIZE 1024
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM " \t\r\n\a"

int funcion_clear(char **args);
int funcion_cd(char **args); 
int funcion_help(char **args);
int funcion_exit(char **args);
int funcion_ls(char **args);
int funcion_pause(char **args);
int funcion_echo(char **args);

char *array_str[] = {
  "clr",
  "cd",
  "help",
  "ls",
  "echo",
  "pause",
  "quit"
 
};

char *array_info[] = {
    "cd - display or change the current directory using <cd parameter>",
    "exit - execute the shall program using <exit>",
    "clear - clear the terminal using <clr>",
    "ls - list the details in the <dir> directory",
    "pause - stop the program using <pause>",
    "echo - print element using <echo parameter>"
  };

int (*array_function[]) (char **) = {
  &funcion_clear,
  &funcion_cd,
  &funcion_help,
  &funcion_ls,
  &funcion_echo,
  &funcion_pause,
  &funcion_exit
 
};

int longitud_array_bit() {
  return sizeof(array_str) / sizeof(char *);
}

int funcion_cd(char **args)
{
 
  if (args[1] != NULL && args[1] != "") {
    if (chdir(args[1]) != 0){ 
      printf("error: direction <%s>doesn't exit \n",args[1]);   
    }
  } else {
      printf("Argument \"cd\"\n");
  }
  system("pwd");
  return 1;
}

int funcion_help(char **args)
{
  printf("Welcome to my shell :\n");
  int i;
  for (i = 0; i < longitud_array_bit()-1; i++) {
    printf("  %s\n", array_info[i]);
  }
  return 1;
}


int funcion_exit(char **args)
{
  return 0;
}


 int funcion_clear(char **args)
{
  if(args[1] == "clear"){
    printf("command clr?");
  }else{
    system("clear");
  }
  return 1;
} 

int funcion_ls(char **args)
{
  system("ls");
  return 1;
} 

int funcion_echo(char **args)
{
  if (args[1] == NULL || args[1] == "") {
     printf("Argument\n");
  }else{
      printf("%s\n",args[1]);
  }
  return 1;
} 


int funcion_pause(char **args)
{
  system("exit");
  return 1;
} 

 

int threadC(char **args)
{
  
  pid_t pid;
  int stat;
  
  pid = fork(); 
  if (pid < 0) { 
    printf("error \n");
  } else if (pid == 0) {
    if (execvp(args[0], args) == -1) printf("error: command does not exit\n");
    exit(EXIT_FAILURE);
  } else {
  
    do {
      waitpid(pid, &stat, WUNTRACED);
    } while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
  }
  return 1;
}


int command(char **args)
{
  int i;
  if (args[0] == NULL) return 1;
  for (i = 0; i < longitud_array_bit(); i++) {
    if (strcmp(args[0], array_str[i]) == 0) {
      return (*array_function[i])(args);
    }
  }
  return threadC(args);
}



char *readC(void)
{
  int bufsize = BUFSIZE;
  int position = 0;
  int var;
  char *buffer = malloc(sizeof(char) * bufsize);
  if (!buffer) {
    printf("error\n");
    exit(EXIT_FAILURE); 
  }
  while (1) {
    var = getchar(); 
    if (var == '\n') {
      buffer[position] = '\0';
      return buffer;
    }else if (var == EOF) {
      exit(EXIT_SUCCESS);
    } else {
      buffer[position] = var;
    }
    position++;
    if (position >= bufsize) {
      bufsize += BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        printf("error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}


char **split(char *line)
{
  int bufsize = TOKEN_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  if (!tokens) {
    printf("error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, TOKEN_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;
    if (position >= bufsize) {
      bufsize += TOKEN_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        printf("error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOKEN_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int main(int argc, char **argv)
{

    char *line;
    char **args;
    int stat;
    do {
      printf("%dshell~$ ",system("pwd"));
      if(argv[1] != NULL){
        line = argv[1];
      }else{
        line = readC();
      }
      args = split(line);
      stat = command(args);
      free(line);
      free(args);
    } while (stat);
    return EXIT_SUCCESS;
 
}
