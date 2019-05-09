#include <stdio.h>

#define MAX_SIZE 100000

struct Stack{
    int array[MAX_SIZE];
    int size;
};

/*  returns new empty stack */
struct Stack newStack();

/*  pushes element to the stack and returns it 
    prints error message if the stack is full and returns the stack*/
struct Stack push(struct Stack st, int element);

/*  returns the index-th element of the stack 
    prints error message and returns -1 if the index is invalid */
int get(struct Stack st, int index);

/*  returns 1 if the stack is empty, otherwise 0 */
int isEmpty(struct Stack st);

/*  returns the next element in the stack 
    prints error message and returns -1 if the stack is empty*/
int peek(struct Stack st);

/*  deletes the next element in the stack and 
    returns the stack */
struct Stack poll(struct Stack st);

/*  prints the stack
    prints error message if the stack is empty */
void printStack(struct Stack st);
