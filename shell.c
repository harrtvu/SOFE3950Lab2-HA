#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define clear() printf("\033[H\033[J")

void cdfunction();

int main() {
    char command;
    printf("Enter an cmd: ");
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



void changeDir(){

}
void clearScreen(){

}
void listContent(){

}
void listEnvironmentStrings(){

}
void displayCommands(){
printf("Printing current dir\n");
	char cwd[100];
	if(getcwd(cwd, sizeof(cwd)) != NULL){
		printf("%s\n", cwd);
	}
}
void displayManual(){

}
void pauseOperation(){

}
void quitShell(){

}
void displayShellEnvironment(){

}
}