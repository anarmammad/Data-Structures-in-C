#include "queue.h"

int main(int argc, char const *argv[]){
    struct Queue q = newQueue();
}

struct Queue newQueue(){
    struct Queue q;
    q.size = 0;
    q.indexOfOldest = 0;
    return q;
}

int isEmpty(struct Queue q){
    return q.size==0;
}

struct Queue enqueue(struct Queue q, int element){
    if(q.size < MAX_SIZE){
        q.array[(q.indexOfOldest + q.size) % MAX_SIZE] = element;
        q.size++;
    }
    else
        printf("Enqueue is impossible: Queue is filled!\n");
    return q;
}

struct Queue dequeue(struct Queue q){
    if(!isEmpty(q)){
        q.size--;
        q.indexOfOldest++;
    }
    else 
        printf("Dequeue is impossible: Queue is empty!\n");
    return q;
}

int get(struct Queue q, int index){
    if(index < q.size && index >= 0)
        return q.array[(q.indexOfOldest + index) % MAX_SIZE];

    printf("Get is impossible: Index is invalid!\n");
    return -1;
}

int peek(struct Queue q){
    if(!isEmpty(q))
        return q.array[q.indexOfOldest];

    printf("Peek is impossible: Queue is empty!\n");
    return -1;
}

void printQueue(struct Queue q){
    if(!isEmpty(q)){
        for (int i = 0; i < q.size; i++){
            printf("<- %d ", get(q, i));
        }
        printf("\n");
    }
    else
        printf("Print is impossible: Queue is empty!\n");
}
