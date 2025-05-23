#include <pthread.h>
#include <stdio.h>

void* threadFunc(void* arg) {
	int n= *(int*)arg;
	for(int i=1; i<= n; i++){
          printf("Thread running with arg: %d\n", i);
fflush(stdout);          // Flush output immediately
        usleep(10000);
}
        return NULL;
}

int main() {
    pthread_t t;
    int val = 42;
    pthread_create(&t, NULL, threadFunc, &val);
 for(int i=1; i<= va`l; i++){
          printf("Main running with arg: %d\n", i);
fflush(stdout);          // Flush output immediately
        usleep(10000);
}    
pthread_join(t, NULL);
    return 0;
}
