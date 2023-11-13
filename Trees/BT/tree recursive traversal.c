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

// Structure to represent a queue node for level order traversal
struct QueueNode {
    Nodeptr node;
    struct QueueNode* next;
};

// Typedef for simplicity
typedef struct QueueNode* QueueNodePtr;

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

// Function to enqueue a node in the queue for level order traversal
void enqueue(QueueNodePtr* front, QueueNodePtr* rear, Nodeptr node) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to dequeue a node from the queue for level order traversal
Nodeptr dequeue(QueueNodePtr* front, QueueNodePtr* rear) {
    if (*front == NULL) {
        return NULL;
    }

    QueueNodePtr temp = *front;
    Nodeptr node = temp->node;

    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);

    return node;
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

// Function for level order traversal
void levelOrderTraversal(Nodeptr root) {
    if (root == NULL) {
        return;
    }

    QueueNodePtr front = NULL;
    QueueNodePtr rear = NULL;

    enqueue(&front, &rear, root);

    while (front != NULL) {
        Nodeptr current = dequeue(&front, &rear);
        printf("%d ", current->data);

        if (current->left != NULL) {
            enqueue(&front, &rear, current->left);
        }

        if (current->right != NULL) {
            enqueue(&front, &rear, current->right);
        }
    }
}

int main() {
    int item;
    printf("Creating the tree : \n");
    printf("Enter the root(-1 to stop) :");
    scanf("%d", &item);
    Nodeptr root = createBinaryTree(item);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Level Order Traversal\n");
        printf("5. Exit\n");
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
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Level Order Traversal: ");
                levelOrderTraversal(root);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}



