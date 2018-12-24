
// Group1: Abderrahman Dandoune, Abdoul Diallo, Nishal Kayharee

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fctrl.h>
#include <string.h>

int main()
{
	char file[30];
	printf("Please enter a file name:\n");
	scanf("%s", file);

	int fd, to_end;
	char* str = "THIS IS THE END OF THE FILE.";
	ssize_t nr;

	fd = open(file, O_WRONLY);
	if (fd == -1){
		printf("Error opening file\n");
		return -1;
	}

	to_end = lseek(fd, 0, SEEK_END);
	nr = write (fd, str, strlen(str));

	if (nr == -1){
		printf("Error writing to file\n");
		return -1;
	}
	printf("'%s' was added to the end of the file.\n", str);

	close(fd);

	return 0;
}