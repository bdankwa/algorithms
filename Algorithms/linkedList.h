#pragma once

typedef struct node {
	int key;
	struct node* next;
	struct node* prev;
}node_t;

typedef struct dlist {
	node_t* head;
	node_t* last;
	int size;
}dlinkedList_t;

dlinkedList_t* init_dllist(void);
int insert_dllist(dlinkedList_t*, int key);
int delete_dllist(dlinkedList_t*, int key);
node_t* search_dllist(dlinkedList_t*, int key);