#include "stack.h"

stack_t init_stack(int MaxLen) {
	stack_t stack;
	stack.buffer = NULL;

	if (MaxLen > 0) {
		stack.buffer = malloc(MaxLen * sizeof(sqnode_t*));
		stack.elements = 0;
		stack.MaxLen = MaxLen;
		stack.head = 0;
		stack.tail = 0;
	}
	return stack;
}

int stack_push(stack_t* stack, void* data, int size) {
	unsigned int index;

	if (stack != NULL && data != NULL && size > 0) {
		index = stack->head % stack->MaxLen;
		if ((stack->head - stack->tail) == (stack->MaxLen - 1)) {
			perror("stack_push: stack is full");
			return 0; // buffer full
		}
		sqnode_t* node = malloc(sizeof(sqnode_t));
		node->data = data;
		node->size = size;

		stack->head++; // This assumes single threaded. This has to be atomic for multithreaded.
		stack->buffer[index] = node;
		stack->elements++;
		return 1;
	}
	else {
		return 0;
	}
}

void* stack_pop(stack_t* stack, int* size) {
	unsigned int index;

	if (stack != NULL && size > 0) {
		if (stack->head == stack->tail) {
			perror("stack_pop: stack is empty");
			return NULL; // buffer is empty
		}
		index = --(stack->head); // This assumes single threaded. This has to be atomic for multithreaded.	
		*size = stack->buffer[index]->size;
		void* data = stack->buffer[index]->data;
		free(stack->buffer[index]);
		stack->elements--;
		return data;
	}
	else {
		return NULL;
	}
}

void stack_destroy(stack_t* stack) {
	free(stack->buffer);
	stack->elements = 0;
	stack->head = 0;
	stack->tail = 0;
	stack->MaxLen = 0;
}