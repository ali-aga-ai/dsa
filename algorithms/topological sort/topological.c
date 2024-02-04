#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    s->items[++s->top] = value;
}

int pop(struct Stack* s) {
    return s->items[s->top--];
}

void topologicalSortUtil(int graph[MAX][MAX], int vertex, int visited[MAX], struct Stack* s, int vertices);

void topologicalSort(int graph[MAX][MAX], int vertices) {
    struct Stack s;
    init(&s);
    int visited[MAX] = {0};

    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, &s, vertices);
        }
    }

    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
}

void topologicalSortUtil(int graph[MAX][MAX], int vertex, int visited[MAX], struct Stack* s, int vertices) {
    visited[vertex] = 1;
    for (int i = 0; i < vertices; ++i) {
        if (graph[vertex][i] && !visited[i]) {
            topologicalSortUtil(graph, i, visited, s, vertices);
        }
    }
    push(s, vertex);
}
