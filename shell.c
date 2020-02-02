#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#define clear() printf("\033[H\033[J")


int main() {
     
    
    
    switch(command)
    {
        case '1':
         cdfunction();
   
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

void cdfunction(){

}