#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define clear() printf("\033[H\033[J")

void displayCommands();

int main() {
	
    printf("1 - Change or present the current directory\n");
    char command;
    printf("Enter cmd: ");
    scanf("%s", &command);
    
    
    switch(command)
    {
        case '1':
         displayCommands();
   
            break;
        case '-':
            printf("do something ");
            break;
        case '*':
            printf("do something ");
            break;
        case '2':
            printf("do something ");
            break;
        
        default:
            printf("Error");
    }
    return 0;
}


void displayCommands(){

    char cmd[50];
    printf("cd - for display the current directory\n");
    printf("cd <directory> - for changing the current directory \n");
    scanf("%s", cmd);
if (strcmp(cmd, "cd") == 0)
{

printf("Printing current directory\n");
	char cwd[100];
	if(getcwd(cwd, sizeof(cwd)) != NULL){
		printf("%s\n", cwd);
	}
}
else {
   chdir("cmd");
	printf("Changed\n");
}
}

void changeDir(){

}
void clearScreen(){

}
void listContent(){

}
void listEnvironmentStrings(){

}

void displayManual(){

}
void pauseOperation(){

}
void quitShell(){

}
void displayShellEnvironment(){

}
