/*Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

struct HeapNode extractMin(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void decreaseKey(struct MinHeap* h, int v, int dist) {
    for (int i = 0; i < h->size; i++) {
        if (h->heap[i].vertex == v) {
            h->heap[i].dist = dist;
            while (i && h->heap[i].dist < h->heap[(i - 1) / 2].dist) {
                swap(&h->heap[i], &h->heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}

int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap heap;
    heap.size = V;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        heap.heap[i].vertex = i;
        heap.heap[i].dist = INT_MAX;
    }

    dist[src] = 0;
    heap.heap[src].dist = 0;

    for (int i = V / 2 - 1; i >= 0; i--)
        heapify(&heap, i);

    while (!isEmpty(&heap)) {
        struct HeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];

        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                decreaseKey(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    struct Graph graph;
    graph.V = 5;

    for (int i = 0; i < graph.V; i++)
        graph.adj[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 4, 1, 3);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 0, 7);

    dijkstra(&graph, 0);

    return 0;
}