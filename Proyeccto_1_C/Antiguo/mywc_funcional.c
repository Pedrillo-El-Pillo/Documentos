//P1-SSOO-23/24

#include <stdio.h>


int main(int argc, char *argv[])
{
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}
    // Open the file using open() system call
    int fd = open(argv[1], 0); 
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    // Read from the file using read() system call
    char buffer[4096]; // Buffer to store read data
    int bytes_read;
    int char_count = 0;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        // Count characters in the buffer
        for (int i = 0; i < bytes_read; i++) {
            if (buffer[i] != '\0') {
                char_count++;
            }
        }
    }

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return -1;
    }

    // Close the file using close() system call
    if (close(fd) == -1) {
        perror("Error closing file");
        return -1;
    }

    printf("Total characters in the file: %d\n", char_count);

    return 0;
}