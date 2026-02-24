/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    struct Node *result = NULL, *temp = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data <= head2->data) {
        result = head1;
        head1 = head1->next;
    } else {
        result = head2;
        head2 = head2->next;
    }

    temp = result;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *temp1 = NULL, *temp2 = NULL, *newNode;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head1 == NULL) {
            head1 = newNode;
            temp1 = head1;
        } else {
            temp1->next = newNode;
            temp1 = newNode;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        if (head2 == NULL) {
            head2 = newNode;
            temp2 = head2;
        } else {
            temp2->next = newNode;
            temp2 = newNode;
        }
    }

    struct Node* mergedHead = mergeLists(head1, head2);

    printList(mergedHead);

    return 0;
}