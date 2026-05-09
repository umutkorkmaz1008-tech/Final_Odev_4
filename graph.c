#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

Node* createNode(int city) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->city = city;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int cities) {

    Graph* graph = (Graph*)malloc(sizeof(Graph));

    graph->numCities = cities;

    int i;

    for(i = 0; i < cities; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {

    Node* newNode = createNode(dest);

    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);

    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(Graph* graph, int start) {

    int visited[MAX] = {0};

    int queue[MAX];

    int front = 0;
    int rear = 0;

    visited[start] = 1;

    queue[rear++] = start;

    printf("\nBFS Gezme Sonucu:\n");

    while(front < rear) {

        int current = queue[front++];

        printf("%s ", graph->cityNames[current]);

        Node* temp = graph->adjLists[current];

        while(temp != NULL) {

            int adj = temp->city;

            if(!visited[adj]) {

                visited[adj] = 1;

                queue[rear++] = adj;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}