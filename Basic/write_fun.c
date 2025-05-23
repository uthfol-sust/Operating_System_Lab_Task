#include<unistd.h>
#include<stdio.h>

int main(){
    int n;
    int  b[30];
    n = read(0,b,30);
    write(1,b,n);

}

