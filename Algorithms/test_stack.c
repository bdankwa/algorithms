#include "stack.h"

void test_stack(void);

void test_stack(void) {
	int buff1[] = { 1, 2 };
	int buff2[] = { 3, 4, 5 };
	double buff3[] = { 6.7, 8.9 };
	char buff4[] = "hello";

	stack_t stack = init_stack(4);
	if (stack.buffer == NULL) {
		return; // something weird happened.
	}

	if (!stack_push(&stack, buff1, sizeof(buff1))) {
		perror("Unable to push buff1 to stack");
	}
	else {
		printf("pushed buff1 on stack \n");
	}
	if (!stack_push(&stack, buff2, sizeof(buff2))) {
		perror("Unable to push buff2 to stack");
	}
	else {
		printf("pushed buff2 on stack \n");
	}
	if (!stack_push(&stack, buff3, sizeof(buff3))) {
		perror("Unable to push buff3 to stack");
	}
	else {
		printf("pushed buff3 on stack \n");
	}
	if (!stack_push(&stack, buff4, sizeof(buff4))) {
		perror("Unable to push buff4 to stack");
	}

	int size;
	double* data3;
	if ((data3 = (double*)stack_pop(&stack, &size)) == NULL) {
		perror("Unable to pop buff1 from stack");
	}
	else {
		printf("poped buff3 from stack \n");
	}
	for (int i = 0; i < size / sizeof(double); i++) {
		printf(" buff3[%i] = %f \n", i, data3[i]);
	}

	int* data2;
	if ((data2 = (int*)stack_pop(&stack, &size)) == NULL) {
		perror("Unable to pop buff2 from stack");
	}
	else {
		printf("poped buff2 from stack \n");
	}
	for (int i = 0; i < size / sizeof(int); i++) {
		printf(" buff2[%i] = %i \n", i, data2[i]);
	}

	if (!stack_push(&stack, buff4, sizeof(buff4))) {
		perror("Unable to push buff4 to stack");
	}
	else {
		printf("pushed buff4 on stack \n");
	}

	char* data4;
	if ((data4 = (int*)stack_pop(&stack, &size)) == NULL) {
		perror("Unable to pop buff1 from stack");
	}
	else {
		printf("poped buff4 from stack \n");
	}
	printf(" buff4 = %s \n", data4);

	(void)stack_pop(&stack, &size); // pop the last element
	(void)stack_pop(&stack, &size); // Stack should be empty
}