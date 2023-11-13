#include <stdio.h>
#include <stdlib.h>

// Structure for the expression tree
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node for the expression tree
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator (+, -, *, /)
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to build an expression tree from a postfix expression
TreeNode* buildExpressionTree(char postfix[]) {
    TreeNode* stack[100];  // Stack to hold tree nodes
    int top = -1;  // Stack pointer

    for (int i = 0; postfix[i] != '\0'; i++) {
        TreeNode* newNode = createNode(postfix[i]);

        if (!isOperator(postfix[i])) {
            // If it's an operand, push it onto the stack
            stack[++top] = newNode;
        } else {
            // If it's an operator, pop two operands from the stack and make them children of the operator
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            // Push the new subtree back onto the stack
            stack[++top] = newNode;
        }
    }

    // The final tree is on top of the stack
    return stack[top];
}

// Function to evaluate the expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (!isOperator(root->data)) {
        // If it's an operand, return its integer value
        return root->data - '0';
    }

    // If it's an operator, evaluate the left and right subtrees recursively
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Perform the operation based on the operator
    switch (root->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }

    return 0;
}

int main() {
     char postfixExpression[50];
    printf("Enter postfix expression:");
    scanf("%s",postfixExpression);

    TreeNode* root = buildExpressionTree(postfixExpression);

    printf("Expression Tree created.\n");

    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}



