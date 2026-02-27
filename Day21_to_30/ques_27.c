/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int findIntersection(struct Node* head1, struct Node* head2) {

    struct Node* ptr1 = head1;

    while (ptr1 != NULL) {
        struct Node* ptr2 = head2;

        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data)
                return ptr1->data;
            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    return -1;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insertEnd(&head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insertEnd(&head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result != -1)
        printf("%d\n", result);
    else
        printf("No Intersection\n");

    return 0;
}