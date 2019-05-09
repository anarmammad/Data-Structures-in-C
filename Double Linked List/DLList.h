#include <stdio.h>
#include <stdlib.h>

struct DLL{
    int value;
    struct DLL *next;
    struct DLL *prev;
};

/*  returns new list */
struct DLL* newDLList(int value);

/*  adds value to the begginning of the list */
void addToBeginning(struct DLL **list, int value);

/*  creates new node and inserts it to the end of the list */
void addToEnd(struct DLL **list, int value);

/*  creates new node and inserts it after the node in the list
    prints error message if the element does not belong to the list */
void insertAfter(struct DLL **list, struct DLL *node, int newValue);

/*  creates new node and inserts it before the node in the list
    prints error message if the element does not belong to the list */
void insertBefore(struct DLL **list, struct DLL *node, int value);

/*  prints the list
    prints error message if the list is empty */
void printDLL(struct DLL *doubleLL);

/*  prints list int reversed order */
void DLL_printReverse_recursion(struct DLL *doubleLL);

/*  prints list int reversed order */
void DLL_printReverse_iteration(struct DLL *doubleLL);