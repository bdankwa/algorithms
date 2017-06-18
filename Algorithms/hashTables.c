#include "hashTables.h"
#include "stdafx.h"

unsigned int new_size = HASH_SIZE;


int hash(int key) {
	return key % new_size;
}

hashTable_t* init_hashTable(void) {

	hashTable_t* hashTable = malloc(sizeof(hashTable_t));
	hashTable->map = malloc(HASH_SIZE * sizeof(dlinkedList_t*));

	for (int i = 0; i < HASH_SIZE; i++) {
		hashTable->map[i] = init_dllist();
	}
	hashTable->curser_index = 0;
	hashTable->curser_node = hashTable->map[0]->head;
	hashTable->size = 0;

	return hashTable;
}

int insert_hashTable(hashTable_t* hashTable, int key, int value) {
	if (hashTable != NULL) {
		//check for 100% load factor and resize array.
		if ((hashTable->size > 0) && (hashTable->size % HASH_SIZE == 0)) {
			hashTable->map = realloc(hashTable->map, 2 * new_size * sizeof(dlinkedList_t*));
			// Initialize newly allocated space
			for (int i = new_size; i < 2 * new_size; i++) {
				hashTable->map[i] = init_dllist();
			}
			new_size = 2 * new_size;
		}
		if (insert_dllist(hashTable->map[hash(key)], key, value)) {
			hashTable->size++;
			return 1;
		}
	}
	return 0;
}

node_t* search_hashTable(hashTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		return search_dllist(hashTable->map[hash(key)], key);
	}
	return NULL;
}

int delete_hashTable(hashTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		if (delete_dllist(hashTable->map[hash(key)], key)) {
			hashTable->size--;
			return 1;
		}
	}
	return 0;
}

void interator_init(hashTable_t* hashTable) {
	hashTable->curser_index = 0;
	hashTable->curser_node = hashTable->map[0]->head;
}

node_t* iterator_next(hashTable_t* hashTable) {	
	node_t* next = hashTable->curser_node;

	if (next != NULL && (next->next != NULL)) {
		hashTable->curser_node = next->next;
	}
	else {
		hashTable->curser_index = (hashTable->curser_index + 1) % new_size;
		hashTable->curser_node = hashTable->map[hashTable->curser_index]->head;
	}
	return next;
}