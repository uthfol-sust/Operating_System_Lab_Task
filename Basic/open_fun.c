#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
   int n,fd;
   char bf[50];

   fd =open("text.txt",O_CREAT|O_WRONLY,0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }
   n = read(fd,bf,10);
    if (fd < 0) {
        perror("Error reading file");
        return 1;
    }
   write(1,bf,10);
}
