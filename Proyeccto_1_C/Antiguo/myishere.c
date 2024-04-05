#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Number of arguments is %i not 3\n",argc);
		return -1;
	}
    
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(argv[1])) == NULL) {
        printf("Directory not found");
        return -1;
    }
    while ((entry = readdir(dir)) != NULL)
      {
        if (strcmp(argv[2], entry->d_name) == 0){ 
        printf("File %s found\n",entry->d_name);}
        closedir(dir);
        }
    return 0;
    printf("File %s not found\n ",entry->d_name);
    closedir(dir);
	return -1;
}