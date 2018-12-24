// Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h> 

int main()
{
    pid_t pid = getpid();
    
    if( pid < 0){
        printf("Error: pid is less than ZERO\n");
        return -1;
    }
    else if( pid == 0 ){
        printf("My pid = 0. It's an idle process\n");
    }
    else if( pid == 1 ){
        printf("My pid = 1. It's an init process\n");
    }
    else {
        printf("My parent pid is %d\n", pid);
    }
    
    pid_t pid_child1 = fork();
    pid_t pid_child2 = fork();
    if( pid_child1 < 0 || pid_child2 < 0 ){
        printf("Error: pid_child is less than ZERO\n");
        return -1;
    }
    else if( pid_child2 > 0 && pid_child1 == 0 ){
        printf("First child pid is %d, its parent pid is %d \n", getpid(), getppid()); 
    }
    else if( pid_child1 > 0 && pid_child2 == 0 ){
        printf("Second child pid is %d, its parent pid is %d \n", getpid(), getppid()); 
    }

    for(int i=0;i<2;i++) 
    wait(NULL);

    return 0;
}
