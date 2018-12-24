/*  Group 1 
    Abdoul Diallo
    Nishal Kayharee
    Abderrahman Dandoune
*/



#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main ()
{



   FILE *file = fopen ("todolist.txt", "r");
   FILE *secondFilePtr = fopen("temp.txt", "w");

   // check if file not null

   if (file == NULL) {
    printf("file could not be read");
    return -1;
   }

   if(secondFilePtr == NULL) {
    printf("Could not write to file");
    return -1;
   }
   
   // to read a line
    char line [1000];
    
    int counter = 0;

    while (fgets (line, sizeof line, file ) != NULL ) 
    {

        if (counter == 2) {
            
            for (int i = 0; i < strlen(line); i++) {
                //printf("%c\n", toupper(line[i]));
                fprintf(secondFilePtr, "%c", toupper(line[i]));
            }
        
        } else {
            //printf("%s\n", line);
            fprintf(secondFilePtr, "%s\n", line);
        
        }
        counter ++;
    }

    // put it back in the original file
    fclose (file);
    fclose(secondFilePtr);
    file = fopen ("todolist.txt", "w");
    secondFilePtr = fopen("temp.txt", "r");


    char lines [1000];
    

    while (fgets (lines, sizeof lines, secondFilePtr) != NULL ) 
    {
        
            //printf("%s\n", line);
            fprintf(file, "%s\n", lines);
        
    }



    fclose (file);
    //fclose(secondFilePtr);



    //===========================


    // rename file
    int ret = rename("todolist.txt", "toDoList.txt");
    
    if(ret == 0) {
        printf("File was renamed \n");
    } else {
        printf("File rename failed \n");
    }


    // close file then reprint

    fclose(secondFilePtr);
    file = fopen("toDoList.txt", "r");

    // printing contents of the file
    char print[200];
    while (fgets (print, sizeof print, file) != NULL ) 
    {
            
                printf("%s\n", print);
    }

    

    remove("temp.txt");
    fclose(secondFilePtr);
    fclose (file);
    return 0;
}

