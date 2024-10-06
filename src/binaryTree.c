#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

// Dynamically allocates and initalises a binary tree node
struct Node *createNode(int val);

// Removes node and it's childern and frees the allocated space
void deleteNode(struct Node *node_ptr);

// Prints the childern of the node
void printChildern(struct Node *node_ptr);

// Add node to the bottom left to right in the tree
void insertNode(struct Node *head, struct Node *node_ptr);

// Example of dynamic allocation in C with binary trees
int binaryTree(int argc, char **argv){
    struct Node *head = createNode(5);
    insertNode(head, createNode(3));
    insertNode(head, createNode(1));
    insertNode(head, createNode(12));
    insertNode(head, createNode(65));
    insertNode(head, createNode(88));

    printf("HEAD\n");
    printChildern(head);
    printf("LEFT BRANCH\n");
    printChildern(head->left);
    printf("LEFT LEFT BRANCH\n");
    printChildern(head->left->left);
    printf("LEFT RIGHT BRANCH\n");
    printChildern(head->left->right);
    printf("RIGHT BRANCH\n");
    printChildern(head->right);

    deleteNode(head->left);
    head->left = NULL;
    printf("HEAD AFTER LEFT DELETE\n");
    printChildern(head);
    deleteNode(head->right);
    head->right = NULL;
    printf("HEAD AFTER RIGHT DELETE\n");
    printChildern(head);

    deleteNode(head);
    return 0;
}

// Dynamically allocates and initalises a binary tree node
struct Node *createNode(int val){
    struct Node *p = malloc(sizeof(struct Node));
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

// Removes node and it's childern and frees the allocated space
void deleteNode(struct Node *node_ptr){
    if(node_ptr->left) deleteNode(node_ptr->left);
    if(node_ptr->right) deleteNode(node_ptr->right);
    free(node_ptr);
}

// Prints the childern of the node
void printChildern(struct Node *node_ptr){
    printf("     (%2d)\n    /    \\\n(%2d)\t  (%2d)\n\n",
            node_ptr->val,
            (node_ptr->left) ? node_ptr->left->val : 0,
            (node_ptr->right) ? node_ptr->right->val : 0);
}

// Add node to the bottom left to right in the tree
void insertNode(struct Node *head, struct Node *node_ptr){
    while(head->right){
        if(!head->left){
            head->left = node_ptr;
            return;
        }
        head = head->left;
    }
    if(!head->left){
        head->left = node_ptr;
        return;
    }
    head->right = node_ptr;
}