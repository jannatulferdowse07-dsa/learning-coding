#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    int value = queue[front];
    front++;
    return value;
}

int isEmpty() {
    if (front == -1 || front > rear) return 1;
    return 0;
}

int main() {
    int vertices, edges;
    int adj[MAX][MAX] = {0}; 
    int visited[MAX] = {0};  

    printf("Enter number of vertices (Max %d): ", MAX);
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (Format: source destination):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int startVertex;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("BFS Traversal output: ");
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");

    return 0;
}
