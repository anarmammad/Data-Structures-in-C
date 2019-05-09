#include "DLList.h"

int main(int argc, char const *argv[]){
    /* testing */
    struct DLL *doubleLL = newDLList(5);
    printDLL(doubleLL);

    addToBeginning(&doubleLL, 3);
    printDLL(doubleLL);

    addToEnd(&doubleLL, 7);
    printDLL(doubleLL);

    insertAfter(&doubleLL,doubleLL->next, 6);
    printDLL(doubleLL);

    DLL_printReverse_iteration(doubleLL);
    DLL_printReverse_recursion(doubleLL);
    return 0;
}


struct DLL* newDLList(int value){
    struct DLL *node = (struct DLL*) calloc(1, sizeof(struct DLL));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;  
}

void addToBeginning(struct DLL **list,int value){
    if(list==NULL){
        (*list) = newDLList(value);
        return;
    }
    struct DLL *node = newDLList(value);
    node->next = *list;
    (*list)->prev = node;
    (*list) = node;
}

void addToEnd(struct DLL **list, int value){
    struct DLL *node = newDLList(value);
    if(list==NULL){
        (*list) = node;
        return;
    }
    struct DLL *temp = (*list);
    while((*list)->next!=NULL)
        (*list) = (*list)->next;
    (*list)->next = node;
    node->prev = (*list);
    (*list) = temp;
}

void insertAfter(struct DLL **list, struct DLL *node, int value){
    int isNodeExistInList = 0;
    struct DLL *temp = (*list);
    while((*list)!=NULL){
        if((*list)==node)
            isNodeExistInList = 1;
        (*list) = (*list)->next;
    }
    (*list) = temp;
    if(!isNodeExistInList){
        printf("Insert After is impossible: Node does not exist in the List!\n");
        return;
    }
    struct DLL *newNode = newDLList(value);
    newNode->next = node->next;
    newNode->prev = node;
    node->next->prev = newNode;
    node->next = newNode;
}

void insertBefore(struct DLL **list, struct DLL *node, int value){
    int isNodeExistInList = 0;
    struct DLL *temp = (*list);
    while((*list)!=NULL){
        if((*list)==node)
            isNodeExistInList = 1;
        (*list) = (*list)->next;
    }
    (*list) = temp;
    if(!isNodeExistInList){
        printf("Insert before is impossible: Node does not exist in the List!\n");
        return;
    }
    struct DLL *newNode = newDLList(value);
    newNode->next = node;
    newNode->prev = node->prev;
    node->prev->next = newNode;
    node->prev = newNode;
}

void printDLL(struct DLL *doubleLL){
    if(doubleLL==NULL){
        printf("The list is NULL\n");
        return;
    }
    printf("%d ", doubleLL->value);
    doubleLL = doubleLL->next;
    while(doubleLL!=NULL){
        printf("-> %d ", doubleLL->value);
        doubleLL = doubleLL->next;
    }
    printf("\n");
}

void DLL_printReverse_recursion(struct DLL *doubleLL){
    if(doubleLL==NULL)
        return;
    if(doubleLL->next!=NULL)
        DLL_printReverse_recursion(doubleLL->next);
    if(doubleLL->next==NULL)
        printf("Reversed by recursion: %d ", doubleLL->value);
    else printf("<- %d%c", doubleLL->value, doubleLL->prev==NULL ? '\n':' ');
    
}

void DLL_printReverse_iteration(struct DLL *doubleLL){
    while(doubleLL->next!=NULL)
        doubleLL = doubleLL->next;
    printf("Reversed by iteration: %d", doubleLL->value);
        doubleLL = doubleLL->prev;
    while(doubleLL!=NULL){
        printf(" <- %d", doubleLL->value);
        doubleLL = doubleLL->prev;
    }
    printf("\n");
}