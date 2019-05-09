#include "stack.h"

int main(int argc, char const *argv[]){
    /* testing */
    return 0;
}

struct Stack newStack(){
    struct Stack newStack;
    newStack.size = 0;
    return newStack;
}

struct Stack push(struct Stack st, int element){
    if(st.size==MAX_SIZE)
        printf("Pull is impossible: The stack is full!\n");
    else 
        st.array[st.size++] = element;
    return st;
}

int get(struct Stack st, int index){
    if(index >= st.size || index < 0){
        printf("Get is impossible: The index %d is invalid!\n", index);
        return -1;
    }
    else return st.array[st.size-1-index];
}

int isEmpty(struct Stack st){
    return st.size==0;
}

int peek(struct Stack st){
    if(isEmpty(st)){
        printf("Peek is impossible: Stack is empty!\n");
        return -1;
    }
    return st.array[st.size-1];
}

struct Stack poll(struct Stack st){
    if(isEmpty(st)){
        printf("Poll is impossible: Stack is empty!\n");
        return st;
    }
    st.size--;
    return st;
}

void printStack(struct Stack st){
    if(st.size==0){
        printf("Print is impossible: Stack is empty!\n");
        return;
    }
    for (int i = 0; i < st.size; i++)
        printf(" <- %d", get(st, i));

    printf("\n");
}
