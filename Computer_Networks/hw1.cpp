/**************************
* Computer Network programming 
* HW1: Word & Character count program
* Name:
* Student ID:
* How to compile:
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>
using namespace std;

#define PMODE 0644

int main(int argc, char *argv[]){
    int fdin, n;
    char buf[BUFSIZ];
    
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file_name \n",argv[0]);
        exit(1);
    }

    if((fdin = open(argv[1], O_RDONLY)) == -1){
        perror(argv[1]);
        exit(2);
    }
    
    while((n = read(fdin, buf, BUFSIZ)) > 0){
        cout << buf ; //printf("%s",buf);
    }

    close(fdin);

    exit(0);
}



   
