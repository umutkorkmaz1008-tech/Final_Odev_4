#include <stdio.h>
#include <string.h>
#include "graph.h"
#include "hash.h"

int main() {

    Graph* graph = createGraph(5);

    strcpy(graph->cityNames[0], "Istanbul");
    strcpy(graph->cityNames[1], "Ankara");
    strcpy(graph->cityNames[2], "Izmir");
    strcpy(graph->cityNames[3], "Bursa");
    strcpy(graph->cityNames[4], "Antalya");

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    HashTable ht;

    initTable(&ht);

    insertPackage(&ht, "PKT101", "Ali");
    insertPackage(&ht, "PKT102", "Ayse");
    insertPackage(&ht, "PKT103", "Mehmet");
    insertPackage(&ht, "PKT104", "Zeynep");
    insertPackage(&ht, "PKT105", "Can");

    searchPackage(&ht, "PKT103");

    bfs(graph, 0);

    printMemory(&ht);

    return 0;
}