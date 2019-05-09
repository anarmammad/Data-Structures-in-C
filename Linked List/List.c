#include "list.h"

int main(int argc, char const *argv[]) 
{
    /* testing */
    return 0;
}

struct List* newList(int value){
    struct List *node = calloc(1, sizeof(struct List));
    node->next = NULL;
    node->value = value;
    return node;
}

int isEmpty(struct List* ll){
    return ll==NULL;
}

void printNode(struct List* ll){
    if(isEmpty(ll)) printf("Print is impossible: The list is empty!\n");
    else printf("address: %p \tvalue: %d \tnext: %p\n", ll, ll->value, ll->next);
}

struct List* addToBeginning(struct List* ll, int value){
    if(isEmpty(ll)) return newList(value);
    struct List *newNode = newList(value);
    newNode->next = ll;
    return newNode;
}

struct List* get(struct List* ll, int index){
    if(isEmpty(ll)){
        printf("Get is impossible: List is empty!\n");
        return NULL;
    }
    if(index < 0){
        printf("Get is impossible: Invalid index!\n");
        return NULL;
    }
    for (int i = 0; i < index; i++){
        ll = ll->next;
        if(ll == NULL){
            printf("Get is impossible: Invalid index!\n");
            return NULL;
        }
    }
    return ll;
}

struct List* getLast(struct List* ll){
    if(isEmpty(ll)){
        printf("Get Last is impossible: List is empty!\n");
        return NULL;
    }
    while(ll->next!=NULL){
        ll=ll->next;
    }
    return ll;
}

void printList(struct List* ll){
    if(isEmpty(ll)){
        printf("Print is impossible: List is empty!\n");
    }
    else for(int i = 0 ; ll!=NULL; ll=ll->next, i++){
        printf("%d-th: ", i);
        printNode(ll);
    }
}

struct List* removeFirst(struct List* ll){
    if(isEmpty(ll)){
        printf("Remove First is impossible: List is empty!\n");
        return NULL;
    }
    return ll->next;
}

struct List* removeLast(struct List* ll){
    if(isEmpty(ll)){
        printf("Remove Last is impossible: List is empty!\n");
        return NULL;
    }
    struct List* temp = ll;
    if(temp==NULL || temp->next==NULL) return NULL; 
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return ll;
}

struct List* removeNode(struct List* ll, struct List* node){
    if(isEmpty(ll)){
        printf("Remove Node is impossible: List is empty!\n");
    } 
    else if(isEmpty(node)){
        printf("Remove Node is impossible: Node is empty!\n");
    } 
    else if(ll==node){
        ll = removeFirst(ll);
    }
    else{
        struct List *temp = getPrevious(ll, node);
        if(temp!=NULL)
            temp->next = node->next;
        else{
            printf("Remove Node is impossible: The element does not belong to list!\n");
        }
    }
    return ll;
}

struct List* getPrevious(struct List* ll, struct List* node){
    struct List* previous = NULL;
    while(ll!=NULL){
        if(ll->next==node){
            previous=ll;
            break;
        }
        ll=ll->next;
    }
    return previous;
}

int contains(struct List* ll, struct List* node){
    while(ll!=NULL){
        if(ll==node) return 1;
        ll=ll->next;
    }
    return 0;
}

struct List* insertAfter(struct List* ll, struct List* node, int value){
    if(contains(ll, node)){
        struct List* temp = newList(value);
        temp->next = node->next;
        node->next = temp;
    }
    else printf("Insert After: The element does not belong to list!\n");
    return ll;
}

struct List* addToEnd(struct List* ll, int value){
    if(isEmpty(ll)) return newList(value);
    struct List *new = newList(value);
    ll = concat(ll, new);
    return ll;
}

struct List* concat(struct List* l1, struct List* l2){
    if(isEmpty(l1)) return l2;
    getLast(l1)->next = l2;
    return l1;
}

int getSize(struct List* ll){
    int i = 0;
    for (i = 0; ll!=NULL; i++) ll = ll->next;
    return i;    
}