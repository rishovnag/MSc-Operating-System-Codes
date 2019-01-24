#include <stdio.h>
#include <pthread.h>
 
int c[2];
const int MAX = 500;
int ans = 0;
 
void lock_init()
{
    c[0] = c[1] = 0;
}
 
void lock(int self)
{
    c[self] = 1;
 
    while (c[1-self]==1) ;
}
 
void unlock(int self)
{
    c[self] = 0;
}
 
void* func(void *s)
{
    int i = 0;
    int self = (int *)s;
    printf("Thread Entered: %d\n", self);
 
    lock(self);
 
    for (i=0; i<MAX; i++)
        ans++;
 
    unlock(self);
}
 
int main()
{
    pthread_t p1, p2;
    lock_init();
 
    pthread_create(&p1, NULL, func, (void*)0);
    pthread_create(&p2, NULL, func, (void*)1);
 
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
 
    printf("Actual Count: %d | Expected Count: %d\n", ans, MAX*2);
 
    return 0;
}
