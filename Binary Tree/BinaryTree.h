#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

/*  Creates new node. */
Node* newNode(int value, Node* left, Node* right);

/*  Compute the depth of a node. */
int depth(Node* root, Node* node);

/*  Returns max height of node in tree. */
int maxHeight(Node* node);

/*  Returns min height of node in tree. */
int minHeight(Node* node);

/*  Return 1 iff (if and only if) the tree is height balanced, 0 otherwise. */
int isBalanced(Node* node); 

/*  Return 1 if tree is complete, 0 otherwise. */
int isComplete(Node* node); 

/*  Returns 1 if tree is empty, 0 otherwise. */
int isEmpty(Node* node);

/*  Returns 1 if tree is full, 0 otherwise. */
int isFull(Node* node); 

/*  Determine if this node is a left child. */
int isLeftChild(Node* node, Node* root);

/*  Determine if this node is a right child. */      
int isRightChild(Node* node, Node* root);

/*  Get left subtree of current node. */
Node* left(Node* node);

/*  Get right subtree of current node. */
Node* right(Node* node);

/*  Get the parent of this node. */
Node* parent(Node* node, Node* root);

/*  Left rotation of tree about this node.
    Node must have a right child. */
Node* rotateLeft(Node* node); 

/*  Right rotation of tree about this node.
    Node must have a left child. */
Node* rotateRight(Node* node); 

/*  Update the left subtree of this node. */
Node* setLeft(Node* node, Node* left);

/*  Update the right subtree of this node. */
Node* setRight(Node* node, Node* right);

/*  Set's value associated with this node. */
Node* setValue(Node* node, int value);

/*  Returns the number of descendants of node. */
int size(Node* node);

/*  Prints a representation of the node. */
void printNode(Node* node);

/*  Prints a representation of the subtree rooted at this node. */
void printSubTree(Node* node);