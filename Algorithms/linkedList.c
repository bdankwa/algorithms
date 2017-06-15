#include "linkedList.h"
#include "stdafx.h""

typedef struct {
	int key;
	node_t* next;
	node_t* prev;
}node_t;

typedef struct {
	node_t* head;
	int size;
}dlinkedList_t;

dlinkedList_t* init_dllist(void) {

}
int insert_dllist(dlinkedList_t* list, int key) {

}
int delete_dllist(dlinkedList_t* list, int key) {

}
dlinkedList_t* search_dllist(dlinkedList_t* list, int key) {

}

void sayHello(void) {
	printf("Hello World \n");
}