#pragma once

void sayHello(void);
dlinkedList_t* init_dllist(void);
int insert_dllist(dlinkedList_t*, int key);
int delete_dllist(dlinkedList_t*, int key);
dlinkedList_t* search_dllist(dlinkedList_t*, int key);