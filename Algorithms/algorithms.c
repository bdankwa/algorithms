// Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "linkedList.h"


int main()
{
	dlinkedList_t* dlist = init_dllist();

	for (int i = 0; i < 10; i++) {
		if (!insert_dllist(dlist, i)) {
			perror("unable to insert into list");
		}
	}

	node_t* next = dlist->head;
	int i = 0;
	while (next != NULL) {
		printf("Node %i : key = %i \n", i, next->key);
		i++;
		next = next->next;
	}	
	int key = 5;
	node_t* node = search_dllist(dlist, key);
	if (node != NULL) {
		printf("found node with key = %i \n", node->key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	key = 21;
	node = search_dllist(dlist, key);
	if (node != NULL) {
		printf("found node with key = %i \n", node->key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	key = 5;
	if (delete_dllist(dlist, key)) {
		printf("deleted node with key = %i \n", key);
	}
	else {
		rintf("Node with key = %i not found \n", key);
	}

	next = dlist->head;
	i = 0;
	while (next != NULL) {
		printf("Node %i : key = %i \n", i, next->key);
		i++;
		next = next->next;
	}

	key = 21;
	if (delete_dllist(dlist, key)) {
		printf("deleted node with key = %i \n", key);
	}
	else {
		printf("Node with key = %i not found \n", key);
	}

	next = dlist->head;
	i = 0;
	while (next != NULL) {
		printf("Node %i : key = %i \n", i, next->key);
		i++;
		next = next->next;
	}


    return 0;
}

