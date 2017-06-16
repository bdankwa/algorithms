#include "linkedList.h"
#include "stdafx.h""

dlinkedList_t* init_dllist(void) {

	dlinkedList_t* list = (dlinkedList_t*) malloc(sizeof(dlinkedList_t));

	if (list != NULL) {
		list->head = NULL;
		list->last = NULL;
		list->size = 0;
	}
	return list;
}

int insert_dllist(dlinkedList_t* list, int key) {
	node_t* new_node = malloc(sizeof(node_t));

	if (new_node == NULL || list == NULL) {
		return 0;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->key = key;

	if (list->last != NULL) {
		new_node->prev = list->last;
		list->last->next = new_node;
		list->last = new_node;
	}
	else {// empty list
		list->head = new_node;
		list->last = list->head;
	}

	list->size++;
	return 1;

}

node_t* search_dllist(dlinkedList_t* list, int key) {
	if (list == NULL || list->head == NULL) {
		return NULL;
	}

	node_t* next = list->head;
	while (next!= NULL) {
		if (next->key == key) {
			return next;
		}
		next = next->next;
	}
	return NULL;
}

int delete_dllist(dlinkedList_t* list, int key) {
	node_t* node = search_dllist(list, key);

	if (node != NULL) {
		if (node->prev == NULL) { // head
			list->head = list->head->next;
			list->head->prev = NULL;
		}
		else if (node->next == NULL){ // tail
			node->prev->next = NULL;
		}
		else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
		list->size--;
		free(node);
		return 1;
	}

	return 0;
}