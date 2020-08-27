#include <iostream>

struct Queue {
	int* data;
	int max_size;
	int size;
};

void Create(Queue& q, int max_size);

void Adding(Queue& q, int value);

int Getting(Queue& q);

void ConsoleOutput(Queue& q);

int MaxMin(Queue& q);
