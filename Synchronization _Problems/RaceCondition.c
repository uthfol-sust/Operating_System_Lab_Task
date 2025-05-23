#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int shared = 1;

void *function1(); 
void *function2(); 

int main()
{
    pthread_t thread1, thread2; 

    pthread_create(&thread1, NULL, function1, NULL); 
    pthread_create(&thread2, NULL, function2, NULL); 

    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 

    printf("The final value of shared variable is: %d\n", shared); 

    return 0; 
} 

void *function1()
{
    int x;
    x = shared;
    printf("Thread1 reads the value of shared variable as %d\n", x); 
    x++;
    printf("Local updation by thread1: %d\n", x);
    sleep(1);
    shared = x;
    printf("Value of shared variable updated by thread1 is: %d\n", shared); 

    return NULL;
}

void *function2() 
{ 
   int x; 
   x = shared; 
   printf("Thread2 reads the value of shared variable as %d\n", x); 
   x--; 
   printf("Local updation by thread2: %d\n", x); 
   sleep(1);
   shared = x; 
   printf("Value of shared variable updated by thread2 is: %d\n", shared); 
   return NULL; 
} 
