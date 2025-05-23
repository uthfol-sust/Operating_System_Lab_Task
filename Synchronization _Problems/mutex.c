#include<pthread.h> 
#include<stdio.h> 
#include<semaphore.h> 
#include<unistd.h> 
void *function1(); 
void *function2(); 
int shared = 1; 
pthread_mutex_t mutex; 
int main() 
{ 
        pthread_mutex_init(&mutex, NULL);
        pthread_t thread1, thread2; 
        pthread_create(&thread1, NULL, function1,NULL); 
        pthread_create(&thread2, NULL, function2, NULL); 
        pthread_join(thread1, NULL); 
        pthread_join(thread2, NULL); 
        printf("The final value of shared value is : %d\n", shared); 
        return 0; 
} 
void *function1() 
{ 
        int x; 
        printf("Thread1 trying to acquire lock\n"); 
        pthread_mutex_lock(&mutex); 
        printf("Thread1 aquire lock\n"); 
        x=shared; 
        printf("Thread1 reads the value of shared variable as %d\n", x); 
        x++; 
        printf("Local updation by thread1 : %d\n",x); 
        sleep(1); //thread1 is preempted by thread2 
        shared=x; //thread 1 updates the value of shared variable 
        printf("value of shared variable update by thread1 is : %d\n", shared); 
        pthread_mutex_unlock(&mutex); 
        printf("Thread1 unlock the mutex\n"); 
} 
void *function2() 
{ 
        int x;
        printf("Thread2 trying to acquire lock\n");
        pthread_mutex_lock(&mutex);
        printf("Thread2 aquire lock\n");
        x=shared;
        printf("Thread2 reads the value of shared variable as %d\n", x); 
        x--;
       printf("Local updation by thread2 : %d\n",x);
       sleep(1); //thread2 is preempted by thread2
       shared=x; //thread 2 updates the value of shared variable
       printf("value of shared variable update by thread2 is : %d\n", shared);
       pthread_mutex_unlock(&mutex);
       printf("Thread2 unlock the mutex\n");
}
