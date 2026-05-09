#ifndef GRAPH_H
#define GRAPH_H

#define MAX 10

typedef struct Node {
    int city;
    struct Node* next;
} Node;

typedef struct Graph {
    int numCities;
    char cityNames[MAX][50];
    Node* adjLists[MAX];
} Graph;

Graph* createGraph(int cities);
void addEdge(Graph* graph, int src, int dest);
void bfs(Graph* graph, int start);

#endif