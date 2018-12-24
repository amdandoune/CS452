// Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    
    if( pid < 0){
        printf("Error: pid is less than ZERO\n");
    }
    else if( pid == 0 ){
        printf("My pid = 0. It's an idle process\n");
    }
    else if( pid == 1 ){
        printf("My pid = 1. It's an init process\n");
    }
    else 
        printf("My pid = %d\n", pid);

    return 0;
}
