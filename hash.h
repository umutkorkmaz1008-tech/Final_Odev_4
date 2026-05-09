#ifndef HASH_H
#define HASH_H

#define TABLE_SIZE 10

typedef struct Package {

    char id[20];
    char receiver[50];

    struct Package* next;

} Package;

typedef struct HashTable {

    Package* table[TABLE_SIZE];

} HashTable;

void initTable(HashTable* ht);

int hashFunction(char* key);

void insertPackage(HashTable* ht, char* id, char* receiver);

void searchPackage(HashTable* ht, char* id);

void printMemory(HashTable* ht);

#endif