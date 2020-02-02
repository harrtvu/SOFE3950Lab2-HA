#include <stdio.h>
int main(int argc, char **argv) {


void cdfunction();



	char command;
    printf("Enter an cmd: ");
    scanf("%s", &command);

    switch(command)
    {
        case '1':
            cdfunction();
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;
        case '/':
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;
        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }
    return EXIT_SUCCESS;
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
