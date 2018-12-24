// Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h> 

int main()
{
    pid_t pid_child = fork();
    if( pid_child < 0 ){
        printf("Error: pid_child is less than ZERO\n");
        return -1;
    }
    else if( pid_child == 0 ){   
        
        DIR *dir = opendir("."); 
        if (dir == NULL) 
        { 
            printf("Current directory could not be openned\n" ); 
            return -1; 
        } 
        
        struct dirent *dir_ent;
        printf("Displaying Current Directory Content from a child process:\n"); 
        while ((dir_ent = readdir(dir)) != NULL){
            printf("\t%s\n", dir_ent->d_name); 
        }
      
        closedir(dir); 
    }

    return 0;
}
