#include <stdio.h>
#include <stdlib.h>

#define T 3  // Minimum degree

// -------- B-Tree Node --------
struct BTreeNode {
    int keys[2*T-1];
    struct BTreeNode* children[2*T];
    int n;       // Current number of keys
    int leaf;    // 1 if leaf node
};

// Create new B-Tree node
struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2*T; i++) node->children[i] = NULL;
    return node;
}

// Traverse (inorder-like)
void traverse(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->n; i++) {
            if (!root->leaf) traverse(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf) traverse(root->children[i]);
    }
}

// Search key in B-Tree
struct BTreeNode* search(struct BTreeNode* root, int k) {
    int i = 0;
    while (i < root->n && k > root->keys[i]) i++;

    if (i < root->n && root->keys[i] == k) return root;

    if (root->leaf) return NULL;
    return search(root->children[i], k);
}

// Split child
void splitChild(struct BTreeNode* parent, int i, struct BTreeNode* y) {
    struct BTreeNode* z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T-1; j++) z->keys[j] = y->keys[j+T];
    if (!y->leaf) {
        for (int j = 0; j < T; j++) z->children[j] = y->children[j+T];
    }
    y->n = T - 1;

    for (int j = parent->n; j >= i+1; j--) parent->children[j+1] = parent->children[j];
    parent->children[i+1] = z;

    for (int j = parent->n-1; j >= i; j--) parent->keys[j+1] = parent->keys[j];
    parent->keys[i] = y->keys[T-1];
    parent->n++;
}

// Insert Non-full
void insertNonFull(struct BTreeNode* root, int k) {
    int i = root->n - 1;

    if (root->leaf) {
        while (i >= 0 && root->keys[i] > k) {
            root->keys[i+1] = root->keys[i];
            i--;
        }
        root->keys[i+1] = k;
        root->n++;
    } else {
        while (i >= 0 && root->keys[i] > k) i--;

        if (root->children[i+1]->n == 2*T-1) {
            splitChild(root, i+1, root->children[i+1]);

            if (k > root->keys[i+1]) i++;
        }
        insertNonFull(root->children[i+1], k);
    }
}

// Insert key
struct BTreeNode* insert(struct BTreeNode* root, int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
        return root;
    }

    if (root->n == 2*T-1) {
        struct BTreeNode* s = createNode(0);
        s->children[0] = root;
        splitChild(s, 0, root);

        int i = 0;
        if (s->keys[0] < k) i++;
        insertNonFull(s->children[i], k);

        return s;
    } else {
        insertNonFull(root, k);
        return root;
    }
}

// -------- MAIN for B-Tree --------
int main() {
    struct BTreeNode* root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- B-Tree Operations ---\n");
        printf("1. Insert\n2. Traverse\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("B-Tree traversal: ");
                traverse(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
