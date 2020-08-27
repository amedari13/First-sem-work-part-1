#include <fstream>
#include <iostream>

struct Stack
{
	int data;
	Stack* next;
};

bool IsEmpty(Stack* size);
int Pop(Stack*& stack);
void Push(Stack*& stack, int d);
void Entering(Stack*& stack);
void FindDelete(Stack*& stack);
void ConsoleOutput(Stack* stack);
void FileOutput(Stack* stack);
void FileInput();
void Clear(Stack*& stack);