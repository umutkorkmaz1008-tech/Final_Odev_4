#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void initTable(HashTable* ht) {

    int i;

    for(i = 0; i < TABLE_SIZE; i++) {

        ht->table[i] = NULL;
    }
}

int hashFunction(char* key) {

    int sum = 0;

    int i;

    for(i = 0; key[i] != '\0'; i++) {

        sum += key[i];
    }

    return sum % TABLE_SIZE;
}

void insertPackage(HashTable* ht, char* id, char* receiver) {

    int index = hashFunction(id);

    Package* newPackage = (Package*)malloc(sizeof(Package));

    strcpy(newPackage->id, id);

    strcpy(newPackage->receiver, receiver);

    newPackage->next = ht->table[index];

    ht->table[index] = newPackage;

    printf("Paket eklendi: %s -> %s\n", id, receiver);
}

void searchPackage(HashTable* ht, char* id) {

    int index = hashFunction(id);

    Package* temp = ht->table[index];

    while(temp != NULL) {

        if(strcmp(temp->id, id) == 0) {

            printf("\nPaket Bulundu!\n");

            printf("Paket ID: %s\n", temp->id);

            printf("Alici: %s\n", temp->receiver);

            return;
        }

        temp = temp->next;
    }

    printf("\nPaket bulunamadi!\n");
}

void printMemory(HashTable* ht) {

    int i;

    printf("\nBELLEK RAPORU\n");

    for(i = 0; i < TABLE_SIZE; i++) {

        Package* temp = ht->table[i];

        while(temp != NULL) {

            printf("Paket: %s | Adres: %p | Next: %p\n",
                   temp->id,
                   temp,
                   temp->next);

            temp = temp->next;
        }
    }
}