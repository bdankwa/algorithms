#include "queue.h"

queue_t init_queue(int MaxLen) {
	queue_t queue;
	queue.buffer = NULL;

	if (MaxLen > 0) {
		queue.buffer = malloc(MaxLen * sizeof(sqnode_t*));
		queue.elements = 0;
		queue.MaxLen = MaxLen;
		queue.head = 0;
		queue.tail = 0;
	}
	return queue;
}

int queue_enqueue(queue_t* queue, void* data, int size) {
	unsigned int index;

	if (queue != NULL && data != NULL && size > 0) {
		index = queue->tail % queue->MaxLen;
		if ((queue->tail - queue->head) == (queue->MaxLen - 1)) {
			perror("queue_enqeue: queue is full");
			return 0; // buffer full
		}
		sqnode_t* node = malloc(sizeof(sqnode_t));
		node->data = data;
		node->size = size;

		queue->tail++; // This assumes single threaded. This has to be atomic for multithreaded.
		queue->buffer[index] = node;
		queue->elements++; // This assumes single threaded. This has to be atomic for multithreaded.	
		return 1;
	}
	else {
		return 0;
	}
}

void* queue_dequeue(queue_t* queue, int* size) {
	unsigned int index;

	if (queue != NULL && size > 0) {
		index = queue->head % queue->MaxLen;
		if (queue->tail == queue->head) {
			perror("queue_enqueue: queue is empty");
			return NULL; // buffer is empty
		}		
		*size = queue->buffer[index]->size;
		void* data = queue->buffer[index]->data;
		free(queue->buffer[index]);
		queue->elements--; // This assumes single threaded. This has to be atomic for multithreaded.	

		queue->head++; // This assumes single threaded. This has to be atomic for multithreaded.	
		return data;
	}
	else {
		return NULL;
	}
}

void queue_destroy(queue_t* queue) {
	free(queue->buffer);
	queue->elements = 0;
	queue->head = 0;
	queue->tail = 0;
	queue->MaxLen = 0;
}