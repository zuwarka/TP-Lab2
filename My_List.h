#pragma once
#include "Price.h"
using namespace std;

class My_List
{
private:
	int m_size = 0;
	Elem* head = NULL;

public:
	My_List();
	My_List(int size);
	~My_List();

	Price* operator[] (int index);

	int get_size();
	void insert(Price* n_data); 
	void remove(int index);
	void save(); 
	void load(); 
};

typedef struct Elem
{
	Price* m_data;
	Elem* next;
} Elem;