#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a node after a specific number in the linked list
void insertAfterNumber(Node *head, int after, int data) {
    Node *current = head;
    while (current != NULL) {
        if (current->data == after) {
            Node *newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return; // Inserted the node, so exit the loop
        }
        current = current->next;
    }
    printf("Number %d not found in the list. Cannot insert.\n", after);
}

// Function to insert a node at a specified position in the linked list
void insertAtPosition(Node **head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position. Cannot insert.\n");
        return;
    }

    if (position == 1 || *head == NULL) {
        insertAtBeginning(head, data);
    } else {
        Node *current = *head;
        int currentPosition = 1;

        while (currentPosition < position - 1 && current != NULL) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL) {
            printf("Position exceeds the length of the list. Cannot insert.\n");
        } else {
            insertAfterNumber(*head, current->data, data);
        }
    }
}
void deleteNode(Node **head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    // Handle the case where the node to be deleted is the first node
    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    // Search for the node to be deleted while keeping track of the previous node
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    // If the node with the given value is not found
    if (current == NULL) {
        printf("Node with value %d not found in the list. Cannot delete.\n", value);
        return;
    }

    // Unlink the node from the linked list and free its memory
    prev->next = current->next;
    free(current);
    printf("Node with value %d deleted.\n", value);
}

// Function to display the linked list
void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL; // Initialize an empty linked list

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    printf("Linked List: ");
    display(head); // Display: 1 -> 2 -> 3 -> NULL

    deleteNode(&head, 2); // Delete node with value 2

    printf("Linked List after deletion: ");
    display(head); // Display: 1 -> 3 -> NULL

    return 0;


}
