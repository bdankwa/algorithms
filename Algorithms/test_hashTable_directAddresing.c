
#include "stdafx.h"
#include "hashTables.h"

void test_DAhashTable(void);

void test_DAhashTable()
{
	time_t t;
	DAhashTable_t hashTable = init_DAhashTable();

	srand((unsigned)time(&t));

	int random;

	for (int i = 0; i < HASH_SIZE; i++) {
		random = rand() % 50;
		printf("Inserting ket %i , value % i\n", i, random);
		if (!insert_DAhashTable(&hashTable, i, random)) {
			perror("unable to insert into hashtable");
		}
	}

	interator_init_DA(&hashTable);
	int i = 0;
	node_t* next;
	printf("Hash Table Size % i\n", hashTable.size);
	while (i < HASH_SIZE) {
		if ((next = iterator_next_DA(&hashTable)) != NULL) {
			printf("Key %i : Value = %i \n", next->key, next->value);
		}
		i++;
	}

	int key = 5;
	node_t* node = search_node_DAhashTable(&hashTable, key);
	if (node != NULL) {
		printf("found node with key = %i, value = %i \n", node->key, node->value);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	key = 21;
	node = search_node_DAhashTable(&hashTable, key);
	if (node != NULL) {
		printf("found node with key = %i , value = %i\n", key, node->key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	key = 5;
	if (delete_DAhashTable(&hashTable, key)) {
		printf("deleted node with key = %i \n", key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	interator_init_DA(&hashTable);
	i = 0;
	while (i < hashTable.size) {
		if ((next = iterator_next_DA(&hashTable)) != NULL) {
			printf("Key %i : Value = %i \n", next->key, next->value);
		}
		i++;
	}


	key = 0;
	if (delete_DAhashTable(&hashTable, key)) {
		printf("deleted node with key = %i \n", key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	interator_init_DA(&hashTable);
	i = 0;
	while (i < hashTable.size) {
		if ((next = iterator_next_DA(&hashTable)) != NULL) {
			printf("Key %i : Value = %i \n", next->key, next->value);
		}
		i++;
	}
}

