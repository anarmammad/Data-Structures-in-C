#include <stdio.h>

#define MAX_SIZE 100000

struct Queue{
    int array[MAX_SIZE];
    int size;
    int indexOfOldest;
};

/*  returns new empty queue */
struct Queue newQueue();

/*  returns 1 if the queue is empty, 0 otherwise */
int isEmpty(struct Queue q);

/*  enqueues element into the queue and
    returns the resulting queue 
    prints error message if the queue is filled */
struct Queue enqueue(struct Queue q, int element);

/*  dequeues the oldest element in the queue and
    returns the resulting queue 
    prints error message if the queue is empty */
struct Queue dequeue(struct Queue q);

/*  index starts from 0
    returns index-th element in the queue
    prints error message if index is invalid and returns -1 */
int get(struct Queue q, int index);

/*  returns oldest element in the queue
    prints error message if the queue is empty and returns -1 */
int peek(struct Queue q);

/*  prints queue
    prints error message if the queue is empty */
void printQueue(struct Queue q);