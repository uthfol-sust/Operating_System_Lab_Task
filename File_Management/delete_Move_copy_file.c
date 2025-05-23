#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

void create_file(const char* filename, const char* content) {
    int fd = open(filename, O_CREAT | O_WRONLY |
O_TRUNC, 0644);
    if (fd == -1) {
        perror("Create");
        return;
    }
    write(fd, content, strlen(content));
    close(fd);
    printf("File '%s' created successfully.\n", filename);
}

void delete_file(const char* filename) {
    if (unlink(filename) == -1) {
        perror("Delete");
        return;
    }
    printf("File '%s' deleted successfully.\n", filename);
}


void move_file(const char* old_name, const char* new_name) {
    if (rename(old_name, new_name) == -1) {
        perror("Move");
        return;
    }
    printf("File moved from '%s' to '%s'.\n", old_name,new_name);
}



void copy_file(const char* source, const char* destination) {
    int src = open(source, O_RDONLY);
    if (src == -1) {
        perror("Open source");
        return;
    }

    int dest = open(destination, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (dest == -1) {
        perror("Create destination");
        close(src);
        return;
    }

    char buffer[BUF_SIZE];
    ssize_t bytes;
    while ((bytes = read(src, buffer, BUF_SIZE)) > 0) {
        write(dest, buffer, bytes);
    }

    close(src);
    close(dest);
    printf("File copied from '%s' to '%s'.\n", source, destination);
}


int main() {
    const char* file1 = "test1.txt";
    const char* file2 = "copy.txt";
    const char* file3 = "moved.txt";

    create_file(file1, "Hello, this is a test file.\n");
    copy_file(file1, file2);
    move_file(file2, file3);
    delete_file(file1);

    return 0;
}
