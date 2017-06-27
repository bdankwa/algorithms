#pragma once
#include "common.h"

typedef struct {
	sqnode_t** buffer;
	int elements;
	int MaxLen;
	int head;
	int tail;
}queue_t;

queue_t init_queue(int len);
int queue_enqueue(queue_t* queue, void* data, int size);
void* queue_dequeue(queue_t* queue, int* size);
void queue_destroy(queue_t* queue);