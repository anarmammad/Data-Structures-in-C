#include <stdio.h>
#include <stdlib.h>

struct List{
    int value;
    struct List *next;
};

/*  creates new list */
struct List* newList(int value);

/*  returns 1 if the list is empty, 0 otherwise */
int isEmpty(struct List* ll);

/*  prints one element of the list
    prints error message if the list is empty */
void printNode(struct List* ll);

/*  adds value to the begginning of the list */
struct List* addToBeginning(struct List* ll, int value);

/*  returns index-th element of the list 
    prints error message and returns empty list if the index is invalid or if the list is empty*/
struct List* get(struct List* ll, int index);

/*  returns last element of the list
    prints error message if the list is empty and returns an empty list */
struct List* getLast(struct List* ll);

/*  prints the list
    prints error message if the list is empty */
void printList(struct List* ll);

/*  removes first element of the list
    prints error message if the list is empty and returns an empty list */
struct List* removeFirst(struct List* ll);

/*  removes last element of the list
    prints error message if the list is empty and returns an empty list */
struct List* removeLast(struct List* ll);

/*  removes the node from the list 
    prints error message if the node or the list is empty */
struct List* removeNode(struct List* ll, struct List* node);

/*  returns previous node from the list
    returns an empty list if node deos not belong to list */
struct List* getPrevious(struct List* ll, struct List* node);

/*  returns 1 if the node contains in list, 0 otherwise */
int contains(struct List* ll, struct List* node);

/*  creates new node and inserts it after the node in the list
    prints error message if the element does not belong to the list */
struct List* insertAfter(struct List* ll, struct List* node, int value);

/*  creates new node and inserts it to the end of the list */
struct List* addToEnd(struct List* ll, int value);

/*  concatenates l2 to the end of l1 */
struct List* concat(struct List* l1, struct List* l2);

/*  returns size of the list */
int getSize(struct List* ll);