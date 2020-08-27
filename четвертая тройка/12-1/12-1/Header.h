struct Tree         
{
	int key;        
	Tree* Left, * Right;
};

void makeTree(Tree*& Root, int value);
Tree* deleting(Tree*& Root, int element);
void output(Tree* Root, int level);
void delAll(Tree*& Root);
int Sum(Tree* Root);