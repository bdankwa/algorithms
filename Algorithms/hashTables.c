#include "hashTables.h"
#include "stdafx.h"

unsigned int new_size = HASH_SIZE;

int hash(int key) {
	return key % new_size;
}

hastTable_t* init_hashTable(void) {

	hastTable_t* hashTable = malloc(sizeof(hastTable_t));
	for (int i = 0; i < HASH_SIZE; i++) {
		hashTable->map[i] = init_dllist();
	}
	hashTable->size = 0;

	return hashTable;
}

int insert_hashTable(hastTable_t* hashTable, int key, int value) {
	if (hashTable != NULL) {
		//TODO: check for load factor and resize array.
		if (insert_dllist(hashTable->map[hash(key)], key, value)) {
			hashTable->size++;
			return 1;
		}
	}
	return 0;
}

node_t* search_hashTable(hastTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		return search_dllist(hashTable->map[hash(key)], key);
	}
	return NULL;
}

int delete_hashTable(hastTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		if (delete_dllist(hashTable->map[hash(key)], key)) {
			hashTable->size--;
			return 1;
		}
	}
	return 0;
}