#include <stdio.h>
#include <stdlib.h>
// Define the structure for a tree node
typedef struct Node {
int data;
struct Node* left;
struct Node* right;
struct Node* parent;
int color; // 0 for black, 1 for red
} Node;
// Define the structure for the tree
typedef struct {
Node* root;
} RedBlackTree;
// Function to create a new node
Node* createNode(int data) {
Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->left = newNode->right = newNode->parent = NULL;
newNode->color = 1; // New node is red
return newNode;
}
// Function to insert a new node into the tree
void insertNode(RedBlackTree* tree, int data) {
Node* newNode = createNode(data);
if (tree->root == NULL) {
tree->root = newNode;
newNode->color = 0; // Root node is black
} else {
Node* current = tree->root;
Node* parent = NULL;
while (current != NULL) {
parent = current;
if (newNode->data < current->data) {
current = current->left;
} else {
current = current->right;
}
}
newNode->parent = parent;
if (newNode->data < parent->data) {
parent->left = newNode;
} else {
parent->right = newNode;
}
}
}
