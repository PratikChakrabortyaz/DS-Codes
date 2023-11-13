#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to search for an item in the binary tree using inorder traversal
int searchItem(Nodeptr root, int item) {
    if (root == NULL) {
        return 0; // Item not found
    }

    // Search in the left subtree
    if (searchItem(root->left, item)) {
        return 1;
    }

    // Check the current node
    if (root->data == item) {
        return 1; // Item found
    }

    // Search in the right subtree
    if (searchItem(root->right, item)) {
        return 1;
    }

    return 0; // Item not found
}

// Function to find the height of the binary tree
int findHeight(Nodeptr root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return the maximum of left and right subtree heights + 1 (for the current node)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to insert an item into the binary tree based on a direction string
Nodeptr insertItem(Nodeptr root, int item, const char* direction) {
    if (root == NULL) {
        return createNode(item);
    }

    int len = strlen(direction);

    Nodeptr current = root;
    for (int i = 0; i < len; i++) {
        if (direction[i] == 'L') {
            if (current->left == NULL) {
                current->left = createNode(item);
            }
            current = current->left;
        } else if (direction[i] == 'R') {
            if (current->right == NULL) {
                current->right = createNode(item);
            }
            current = current->right;
        }
    }

    return root;
}

// Function for inorder traversal
void inorderTraversal(Nodeptr root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Nodeptr root = NULL;
    int choice, item;
    char direction[50];

    do {
        printf("\nMenu:\n");
        printf("1. Create Binary Tree\n");
        printf("2. Search Item in Binary Tree\n");
        printf("3. Find Height of Binary Tree\n");
        printf("4. Insert Item into Binary Tree\n");
        printf("5. Inorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating the tree : \n");
                printf("Enter the root (-1 to stop): ");
                scanf("%d", &item);
                root = createBinaryTree(item);
                break;

            case 2:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Enter the item to search: ");
                scanf("%d", &item);
                if (searchItem(root, item)) {
                    printf("Item found in the tree.\n");
                } else {
                    printf("Item not found in the tree.\n");
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Height of the tree: %d\n", findHeight(root));
                break;

            case 4:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Enter the item to insert: ");
                scanf("%d", &item);
                printf("Enter the direction (e.g., LLR): ");
                scanf("%s", direction);
                root = insertItem(root, item, direction);
                printf("Item inserted into the tree.\n");
                break;

            case 5:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
