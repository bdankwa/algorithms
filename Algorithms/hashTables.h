#pragma once
#include "linkedList.h"

#define HASH_SIZE 10

typedef struct {
	dlinkedList_t** map; // NOTE: Pointer-to-pointer definition required to be able to implement dynamic re-sizing.
	int curser_index;
	node_t* curser_node;
	int size;
}hashTable_t;

hashTable_t* init_hashTable(void);
int insert_hashTable(hashTable_t* hashTable, int key, int value);
node_t* search_hashTable(hashTable_t* hashTable, int key);
int delete_hashTable(hashTable_t* hashTable, int key);
void interator_init(hashTable_t* hashTable);
node_t* iterator_next(hashTable_t* hashTable);
