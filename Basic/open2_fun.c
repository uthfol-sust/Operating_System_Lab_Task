#include<fcntl.h>
#include<unistd.h>

int main()
{
  int n,fd;
  char bf[50];

  fd = open("text.txt",O_RDONLY);
  n = read(fd,bf,10);
  write(1,bf,n);

}
