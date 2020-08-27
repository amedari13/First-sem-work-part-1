#pragma once

#include <iostream>

struct Record
{
	int empty;
	const char* name;
};

struct HashTable
{
	int size;
	Record data[16];
};


unsigned Hash(const char*);
void Init(HashTable& table);
void Add(HashTable& table, const char*);
bool Find(HashTable& table, const char*);
void PrintTable(HashTable& table);
bool Delete(HashTable& table, const char*);

