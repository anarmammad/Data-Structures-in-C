#include "BinaryTree.h"

int main(int argc, char const *argv[])
{
    /* tesing */
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

    printNode(parent(node9, root));
    printNode(parent(root, root));
    return 0;
}

Node* newNode(int value, Node* left, Node* right){
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int depth(Node* root, Node* node){
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

int maxHeight(Node* node){
    if(node==NULL) return 0;
    else{
        int righDepth = maxHeight(node->right);
        int leftDepth = maxHeight(node->left);
        if(righDepth > leftDepth) return righDepth+1;
        else return leftDepth+1;
    }
}

int minHeight(Node* node){
    if(node==NULL) return 0;
    else{
        int righDepth = minHeight(node->right);
        int leftDepth = minHeight(node->left);
        if(righDepth < leftDepth) return righDepth+1;
        else return leftDepth+1;
    }
}

int isBalanced(Node* node){
    if (node == NULL) 
        return 1; 

    if(abs(maxHeight(node->left) - maxHeight(node->right)) <= 1)
        if(isBalanced(node->left) && isBalanced(node->right))
            return 1;
    return 0;
}

int isComplete(Node* node){
    /* soon */
}

int isEmpty(Node* node){
    return node==NULL;
}

int isFull(Node* node){
    if(node==NULL) return 1;

    if(node->left==NULL && node->right==NULL) return 1; // is leaf

    if(node->left!=NULL && node->right!=NULL) return isFull(node->left) && isFull(node->right);

    return 0;
}

int isLeftChild(Node* node, Node* root){
    Node* parentNode = parent(node, root);
    return parentNode->left==node;
}

int isRightChild(Node* node, Node* root){
    Node* parentNode = parent(node, root);
    return parentNode->right==node;
}

Node* left(Node* node){
    return node->left;
}

Node* right(Node* node){
    return node->right;
}

Node* parent(Node* node, Node* root){
    if(root==node || root==NULL || node==NULL) return NULL;

    if(root->left == node || root->right == node) return root;

    Node* possibleParent = parent(node, root->left);
    if(possibleParent != NULL) return possibleParent;

    possibleParent = parent(node, root->right);
    if(possibleParent != NULL) return possibleParent;

    return NULL;
}
Node* rotateLeft(Node* node){
    if(node->right==NULL){
        printf("The node does not have right child!\n");
        return node;
    }
    Node* pivot = right(node);
    Node* subtree = pivot->left;
    pivot->left = node;
    node->right = subtree;

    return pivot;
}

Node* rotateRight(Node* node){
    if(node->left==NULL){
        printf("The node does not have left child!\n");
        return node;
    }
    Node* pivot = left(node);
    Node* subtree = pivot->right;
    pivot->right = node;
    node->left = subtree;

    return pivot;
}

Node* setLeft(Node* node, Node* left){
    node->left = left;
    return node;
}

Node* setRight(Node* node, Node* right){
    node->right = right;
    return node;
}

Node* setValue(Node* node, int value){
    node->value = value;
    return node;
}

int	size(Node* root){
    if (root == NULL) 
        return 0; 
    return 1 + size(root->left) + size(root->right); 
}

void printNode(Node* node){
    if(node==NULL){
        printf("Node is NULL!\n");
        return;
    }
    printf(" \t\tValue \tAddress\n");
    printf("Node: \t\t%d \t%p\n", node->value, node);
    if(node->left!=NULL)
        printf("L-Child: \t%d \t%p\n", node->left->value, node->left);
    if(node->right!=NULL)    
        printf("R-Child: \t%d \t%p\n", node->right->value, node->right);
    printf("\n");
}

void printSubTree(Node* node){
    /* soon */
}