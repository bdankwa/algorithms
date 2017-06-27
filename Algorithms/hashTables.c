#include "hashTables.h"

unsigned int new_size = HASH_SIZE;


int hash(int key) {
	return key % new_size;
}

int hash_DA(int i, int key) {
	return (hash(key) + i) % new_size; // Linear probing
}

hashTable_t init_hashTable(void) {

	hashTable_t hashTable;
	hashTable.map = malloc(HASH_SIZE * sizeof(dlinkedList_t*));

	for (int i = 0; i < HASH_SIZE; i++) {
		hashTable.map[i] = init_dllist();
	}
	hashTable.curser_index = 0;
	hashTable.curser_node = hashTable.map[0]->head;
	hashTable.size = 0;

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
	if (hashTable != NULL) {
		hashTable->curser_index = 0;
		hashTable->curser_node = hashTable->map[0]->head;
	}
}

node_t* iterator_next(hashTable_t* hashTable) {	
	if (hashTable == NULL) {
		return NULL;
	}

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

DAhashTable_t init_DAhashTable(void) {
	DAhashTable_t hashTable;
	hashTable.map = malloc(HASH_SIZE * sizeof(node_t));
	for (int i = 0; i < HASH_SIZE; i++) {
		hashTable.map[i] = NULL;
	}
	hashTable.curser = 0;
	hashTable.size = 0;

	return hashTable;
}

int insert_DAhashTable(DAhashTable_t* hashTable, int key, int value) {
	if (hashTable != NULL) {
		node_t* node = malloc(sizeof(node_t));
		node->key = key;
		node->value = value;
		node->next = NULL;
		node->prev = NULL;

		int i = 0;
		int j = 0;
		while (i < new_size) {
			j = hash_DA(i, key);
			if (hashTable->map[j] == NULL) {
				hashTable->map[j] = node;
				hashTable->size++;
				return 1;
			}
			else {
				i++;
			}
		}
		// TODO: Implement dynamic resizing
		return 0;
	}
	else {
		return 0;
	}
}

node_t* search_node_DAhashTable(DAhashTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		int i = 0;
		int j = 0;
		while (i < new_size) {
			j = hash_DA(i, key);
			if (hashTable->map[j]->key == key) {
				return hashTable->map[j];
			}
			else {
				i++;
			}
		}
		return NULL;
	}
	else {
		return NULL;
	}
}

int search_idx_DAhashTable(DAhashTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		int i = 0;
		int j = 0;
		while (i < new_size) {
			j = hash_DA(i, key);
			if (hashTable->map[j]->key == key) {
				return j;
			}
			else {
				i++;
			}
		}
		return -1;
	}
	else {
		return -1;
	}
}

int delete_DAhashTable(DAhashTable_t* hashTable, int key) {
	if (hashTable != NULL) {
		int i = search_idx_DAhashTable(hashTable, key);
		if (i != -1) {
			free(hashTable->map[i]);
			hashTable->map[i] = NULL;
			hashTable->size--;
		}
	}
	else {
		return 0;
	}
	return 1;
}

void interator_init_DA(DAhashTable_t* hashTable) {
	if (hashTable != NULL) {
		hashTable->curser = 0;
	}
}

node_t* iterator_next_DA(DAhashTable_t* hashTable) {
	node_t* node = NULL;
	if (hashTable != NULL) {
		while ((node = hashTable->map[hashTable->curser++]) == NULL && hashTable->curser < HASH_SIZE);
	}
	return node;
}