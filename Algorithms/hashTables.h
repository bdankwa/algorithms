#pragma once
#include "linkedList.h"

#define HASH_SIZE 10
// Chaining
typedef struct {
	dlinkedList_t** map; // NOTE: Pointer-to-pointer definition required to be able to implement dynamic re-sizing.
	int curser_index;
	node_t* curser_node;
	int size;
}hashTable_t;

// Direct Addressing
typedef struct {
	node_t** map;
	int curser;
	int size;
}DAhashTable_t; 

// Chaining
hashTable_t init_hashTable(void);
int insert_hashTable(hashTable_t* hashTable, int key, int value);
node_t* search_hashTable(hashTable_t* hashTable, int key);
int delete_hashTable(hashTable_t* hashTable, int key);
void interator_init(hashTable_t* hashTable);
node_t* iterator_next(hashTable_t* hashTable);

// Direct Addressing
DAhashTable_t init_DAhashTable(void);
int insert_DAhashTable(DAhashTable_t* hashTable, int key, int value);
node_t* search_node_DAhashTable(DAhashTable_t* hashTable, int key);
int search_idx_DAhashTable(DAhashTable_t* hashTable, int key);
int delete_DAhashTable(DAhashTable_t* hashTable, int key);
void interator_init_DA(DAhashTable_t* hashTable);
node_t* iterator_next_DA(DAhashTable_t* hashTable);

