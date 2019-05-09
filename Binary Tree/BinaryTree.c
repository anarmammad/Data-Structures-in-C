#include "BinaryTree.h"

int main(int argc, char const *argv[])
{
    Node* root = newNode(0, NULL, NULL);
    Node* node1 = newNode(1, NULL, NULL);
    Node* node2 = newNode(2, NULL, NULL);

    root = setLeft(root, node1);
    root = setRight(root, node2);

    node1 = setLeft(node1, newNode(3, NULL, NULL));
    node1 = setRight(node1, newNode(4, NULL, newNode(7, NULL, NULL)));

    node2 = setLeft(node2, newNode(6, NULL, NULL));
    Node* node9 = newNode(9, NULL, NULL);
    node2 = setRight(node2, newNode(5, NULL, newNode(8, NULL, node9)));

    printNode(root);
    printf("%d\n", depth(root, node9));

    return 0;
}

Node* newNode(int value, Node* left, Node* right){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int	depth(Node* root, Node* node){
    /* check if it's working */
    int counter = 0;
    if(root==NULL) return 0;
    else 
        if(root==node) return 1;
    else {
        if((counter = depth(root->left, node)) > 0){
            counter++;
        }
        else if((counter = depth(root->right, node)) > 0){
            counter++;
        } 
    }
    return counter;
}

int	height(Node* node){
    /* soon */
}

int	isBalanced(Node* node){
    /* soon */
}

int isComplete(Node* node){
    /* soon */
}

int isEmpty(Node* node){
    return node==NULL;
}

int isFull(Node* node){
    /* soon */
}

Node* setRight(Node* node, Node* right){
    node->right = right;
    return node;
}

Node* setLeft(Node* node, Node* left){
    node->left = left;
    return node;
}

void printNode(Node* node){
    if(node==NULL){
        printf("Node is NULL");
    }
    printf(" \t\tValue \tAddress\n");
    printf("Node: \t\t%d \t%p\n", node->value, node);
    if(node->left!=NULL)
        printf("L-Child: \t%d \t%p\n", node->left->value, node->left);
    if(node->right!=NULL)    
        printf("R-Child: \t%d \t%p\n", node->right->value, node->right);
    printf("\n");
}