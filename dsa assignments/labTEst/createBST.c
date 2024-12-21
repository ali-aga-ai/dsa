#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else {
        if (val > root->val) {
            root->right = insert(root->right, val);
        } else {
            root->left = insert(root->left, val);
        }
    }
    return root;
}

int findMax(struct Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->val;
}

int main() {
    int n, val;
    scanf("%d", &n);
    struct Node* root = NULL;
    // Inserting elements into BST
    root = insert(root, 50);

    for (int i = 1; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val); // Update root after insertion
    }

    printf("%d", findMax(root));

    return 0;
}
