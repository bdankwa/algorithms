#pragma once
#include "linkedList.h"

#define HASH_SIZE 10

typedef struct {
	dlinkedList_t* map[HASH_SIZE];
	int size;
}hastTable_t;

hastTable_t* init_hashTable(void);
int insert_hashTable(hastTable_t* hashTable, int key, int value);
node_t* search_hashTable(hastTable_t* hashTable, int key);
int delete_hashTable(hastTable_t* hashTable, int key);
