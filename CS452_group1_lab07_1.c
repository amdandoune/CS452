// part 1
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

int main(){
    printf("\nThis part belongs to the file name: CS452_group1_lab07_1.c, its pid is %d \n\n", getpid());
    char *args[] = {"CS452_group1_lab07_2", NULL};
    int ret;
    ret = execv("CS452_group1_lab07_2", args);
    if(ret == -1){
        printf("Execv Error \n");
    }
    printf("Do not show this.");
    return 0;
}
