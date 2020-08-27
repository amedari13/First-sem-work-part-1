struct Data {
	char adress[10];
	char name[10];
	int year;
};

struct List { Data data; List* next; };

struct HashTable {
	List *table[20];
};

unsigned Hash(int);
void Init(HashTable& table);
void Add(HashTable& table, Data);
bool Find(HashTable& table, int);
void PrintTable(HashTable& table);
bool Delete(HashTable& table, int);
