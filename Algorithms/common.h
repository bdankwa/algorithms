#pragma once
#include "stdafx.h"
typedef struct node {/***NOTE THE DEFINITION***********/
	int key;
	int value;
	struct node* next;
	struct node* prev;
}node_t;

typedef struct {
	void* data;
	int size;
}sqnode_t;

