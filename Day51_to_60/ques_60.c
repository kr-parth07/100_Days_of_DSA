/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct Node* temp = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(&q);

        if (i < n) {
            curr->left = createNode(arr[i++]);
            enqueue(&q, curr->left);
        }

        if (i < n) {
            curr->right = createNode(arr[i++]);
            enqueue(&q, curr->right);
        }
    }
    return root;
}

int isComplete(struct Node* root) {
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int flag = 0;

    while (!isEmpty(&q)) {
        struct Node* curr = dequeue(&q);

        if (curr == NULL) {
            flag = 1;
        } else {
            if (flag) return 0;

            enqueue(&q, curr->left);
            enqueue(&q, curr->right);
        }
    }
    return 1;
}

int isHeap(struct Node* root) {
    if (!root) return 1;

    if (root->left) {
        if (root->data > root->left->data)
            return 0;
    }

    if (root->right) {
        if (root->data > root->right->data)
            return 0;
    }

    return isHeap(root->left) && isHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isComplete(root) && isHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}