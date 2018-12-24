// part 2
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

int main(){
    printf("This part has been called by execv() and belongs to the file name: CS452_group1_lab07_2.c, its pid is %d \n\n", getpid());
    return 0;
}
