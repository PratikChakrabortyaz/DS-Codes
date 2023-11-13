#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Typedef for simplicity
typedef struct Node* Nodeptr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a binary tree recursively
Nodeptr createBinaryTree(int item) {
    int x;
    if (item != -1) {
        Nodeptr root = createNode(item);

        printf("Enter the left child of %d: ", item);
        scanf("%d", &x);
        root->left = createBinaryTree(x);

        printf("Enter the right child of %d: ", item);
        scanf("%d", &x);
        root->right = createBinaryTree(x);

        return root;
    }

    return NULL;
}

// Function for inorder traversal
void inorderTraversal(Nodeptr root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal
void preorderTraversal(Nodeptr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal
void postorderTraversal(Nodeptr root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int item;
    printf("Creating the tree : \n");
    printf("Enter the root(-1 to stop) :");
    scanf("%d",&item);
    Nodeptr root = createBinaryTree(item);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                break;

            case 2:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                break;

            case 3:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}


