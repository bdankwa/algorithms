#include "linkedList.h"
#include "stdafx.h"

dlinkedList_t* init_dllist(void) {

	dlinkedList_t* list = (dlinkedList_t*) malloc(sizeof(dlinkedList_t));

	if (list != NULL) {
		list->head = NULL;
		list->last = NULL;
		list->size = 0;
	}
	return list;
}

int insert_dllist(dlinkedList_t* list, int key, int value) {
	node_t* new_node = malloc(sizeof(node_t));

	if (new_node == NULL || list == NULL) {
		perror("insert_dllist: null pointer");
		return 0;
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->key = key;
	new_node->value = value;

	if (list->last != NULL) {
		/*******************************************
		* Insert node immediately in front of the
		* first node with with a larger key. If
		* no such node is found, insert node at the
		* end of the list. -- Sorted by key
		*******************************************/		
		node_t* next = list->head;
		while (next != NULL) {
			if (next->key >= key) {
				if (list->head->key >= key) {//less than head
					list->head = new_node;
				}
				else if (next->prev != NULL)  { //at least two nodes
					new_node->prev = next->prev;
					next->prev->next = new_node;
				}
				else { // skip the head if multiple nodes exist
					;
				}
				new_node->next = next;
				next->prev = new_node;
				list->size++;
				return 1;
			}
			next = next->next;
		}
		/////////////////////////////////////////////////////
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
		perror("search_dllist: null pointer");
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
		if (node->prev == NULL && (list->head->next != NULL)) { // head with additional nodes
			list->head = list->head->next;
			list->head->prev = NULL;
		}
		else if (list->head == list->last) { // only head remaining
			list->head = NULL;
			list->last = NULL;
		}
		else if (node->next == NULL){ // tail			
			node->prev->next = NULL;
			list->last = node->prev;
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