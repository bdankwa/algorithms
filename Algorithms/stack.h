#pragma once
#include "common.h"
typedef struct {
	sqnode_t** buffer;
	int elements;
	int MaxLen;
	int head;
	int tail;
}stack_t;

stack_t init_stack(int len);
int stack_push(stack_t* stack, void* data, int size);
void* stack_pop(stack_t* stack, int* size);
void stack_destroy(stack_t* stack);