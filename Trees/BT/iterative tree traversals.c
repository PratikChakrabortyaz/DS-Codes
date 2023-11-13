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

// Structure to represent a stack node
struct StackNode {
    Nodeptr node;
    struct StackNode* next;
};

// Typedef for simplicity
typedef struct StackNode* StackNodePtr;

// Function to create a new node
Nodeptr createNode(int data) {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to push a node onto the stack
void push(StackNodePtr* stack, Nodeptr node) {
    StackNodePtr newNode = (StackNodePtr)malloc(sizeof(struct StackNode));
    newNode->node = node;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a node from the stack
Nodeptr pop(StackNodePtr* stack) {
    if (*stack == NULL) {
        return NULL;
    }
    Nodeptr poppedNode = (*stack)->node;
    StackNodePtr temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return poppedNode;
}

// Function for iterative inorder traversal using a stack
void iterativeInorderTraversal(Nodeptr root) {
    StackNodePtr stack = NULL;
    Nodeptr current = root;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function for iterative preorder traversal using a stack
void iterativePreorderTraversal(Nodeptr root) {
    StackNodePtr stack = NULL;
    push(&stack, root);

    while (stack != NULL) {
        Nodeptr current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(&stack, current->right);
        }

        if (current->left != NULL) {
            push(&stack, current->left);
        }
    }
}

// Function for iterative postorder traversal using two stacks
void iterativePostorderTraversal(Nodeptr root) {
    if (root == NULL) {
        return;
    }

    StackNodePtr stack1 = NULL;
    StackNodePtr stack2 = NULL;

    push(&stack1, root);

    while (stack1 != NULL) {
        Nodeptr current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL) {
            push(&stack1, current->left);
        }

        if (current->right != NULL) {
            push(&stack1, current->right);
        }
    }

    while (stack2 != NULL) {
        Nodeptr current = pop(&stack2);
        printf("%d ", current->data);
    }
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

int main() {
    int item;
    printf("Creating the tree : \n");
    printf("Enter the root(-1 to stop) :");
    scanf("%d", &item);
    Nodeptr root = createBinaryTree(item);

    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Iterative Inorder Traversal\n");
        printf("2. Iterative Preorder Traversal\n");
        printf("3. Iterative Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Iterative Inorder Traversal: ");
                iterativeInorderTraversal(root);
                break;

            case 2:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Iterative Preorder Traversal: ");
                iterativePreorderTraversal(root);
                break;

            case 3:
                if (root == NULL) {
                    printf("No tree exists. Please create a tree first.\n");
                    break;
                }
                printf("Iterative Postorder Traversal: ");
                iterativePostorderTraversal(root);
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
