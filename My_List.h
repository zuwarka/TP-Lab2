﻿#pragma once
#include "Price.h"
using namespace std;

typedef struct Elem
{
	Price* m_data;
	Elem* next;
	Elem* prev;
} Elem;

class My_List //двусвязный список
{
private:
	int m_size = 0;
	Elem* head = NULL;
	Elem* tail = NULL;

public:
	My_List();
	My_List(int size);
	~My_List();

	Price* operator[] (int index);

	int get_size();
	void push_head(Price* n_data); 
	void push_tail(Price* n_data); 
	void insert(Price* n_data, int index);
	void remove(int index); //удалить элемент из списка
	void sort(); //пузырьковая сортировка магазинов по алфавиту
	void swap(Price* other, Price* another); //перемена местами двух элементов списка
	void finding(string name); //поиск элементов списка по параметру с клавиатуры
};