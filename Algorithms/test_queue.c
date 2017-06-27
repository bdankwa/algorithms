#include "queue.h"

void test_queue(void);

void test_queue(void) {
	int buff1[] = { 1, 2 };
	int buff2[] = { 3, 4, 5 };
	double buff3[] = { 6.7, 8.9 };
	char buff4[] = "hello";

	queue_t queue = init_queue(4);
	if (queue.buffer == NULL) {
		return; // something weird happened.
	}

	if (!queue_enqueue(&queue, buff1, sizeof(buff1))) {
		perror("Unable to enqueue buff1");
	}
	else {
		printf("enqueued buff1 \n");
	}
	if (!queue_enqueue(&queue, buff2, sizeof(buff2))) {
		perror("Unable to enqueue buff2");
	}
	else {
		printf("enqueued buff2 \n");
	}
	if (!queue_enqueue(&queue, buff3, sizeof(buff3))) {
		perror("Unable to enqueue buff3");
	}
	else {
		printf("enqueued buff3 \n");
	}
	if (!queue_enqueue(&queue, buff4, sizeof(buff4))) {
		perror("Unable to enqueue buff4");
	}

	int size;
	int* data1;
	if ((data1 = (int*)queue_dequeue(&queue, &size)) == NULL) {
		perror("Unable to dequeue buff1");
	}
	else {
		printf("dequeued buff1 \n");
	}
	for (int i = 0; i < size / sizeof(int); i++) {
		printf(" buff1[%i] = %i \n", i, data1[i]);
	}

	int* data2;
	if ((data2 = (int*)queue_dequeue(&queue, &size)) == NULL) {
		perror("Unable to dequeue buff2");
	}
	else {
		printf("dequeued buff2 \n");
	}
	for (int i = 0; i < size / sizeof(int); i++) {
		printf(" buff2[%i] = %i \n", i, data2[i]);
	}

	if (!queue_enqueue(&queue, buff4, sizeof(buff4))) {
		perror("Unable to dequeue buff4");
	}
	else {
		printf("enqueued buff4 \n");
	}

	double* data3;
	if ((data3 = (double*)queue_dequeue(&queue, &size)) == NULL) {
		perror("Unable to dequeue buff3");
	}
	else {
		printf("dequeued buff3 \n");
	}

	for (int i = 0; i < size / sizeof(double); i++) {
		printf(" buff3[%i] = %f \n", i, data3[i]);
	}

	(void)queue_dequeue(&queue, &size); // dequeue the last element
	(void)queue_dequeue(&queue, &size); // queue should be empty
}