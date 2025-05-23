#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define BUF_SIZE 1024

void create_file(const char* filename, const char* content) {
    int fd = open(filename, O_CREAT | O_WRONLY |O_TRUNC, 0644);
    if (fd == -1) {
        perror("Create");
        return;
    }
    write(fd, content, strlen(content));
    close(fd);
    printf("File '%s' created successfully.\n", filename);
}


int main() {
    const char* file1 = "test1.txt";

    create_file(file1, "Hello, this is a test file.\n");

    return 0;
}
