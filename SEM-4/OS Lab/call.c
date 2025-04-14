#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <fcntl.h>

int main() { 
    int f = fork(); 
    if (f < 0) { 
        printf("Fork failed\n"); 
    } 
    else if (f == 0) { 
        printf("Child process: %d\n", getpid()); 
        printf("Parent process: %d\n", getppid());
        printf("Fork return value in child: %d\n", f);

        int fd = open("test.txt", O_RDONLY);
        if (fd < 0) {
            printf("Error opening file\n");
            return 1;
        }

        char buffer[1024];
        int bytes_read;

        printf("\nReading file contents:\n");
        printf("--------------------\n");
        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }
        
        close(fd);
    } 
    else { 
        printf("Parent process: %d\n", getpid()); 
        printf("Child process: %d\n", f); 
        printf("Fork return value in parent: %d\n", f);
    } 
    return 0; 
} 