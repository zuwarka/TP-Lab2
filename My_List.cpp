#include <iostream>
#include <cstdlib>
#include <string>
#include "My_List.h"

using namespace std;

My_List::My_List() : m_size(0), head(NULL), tail(NULL) {}

My_List::My_List(int size) : head(NULL), tail(NULL) { this->m_size = size; }

My_List::~My_List()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Price();
			delete(buffer);
		}
		head->m_data->~Price();
		delete(head);
	}
}

Price* My_List::operator[] (const int index)
{
	if ((index >= m_size) || (index < 0))
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

void My_List::push_head(Price* n_data)
{
	Elem* tmp = new Elem;
	tmp->prev = 0;
	tmp->m_data = n_data;
	tmp->next = head;

	if (head != NULL)
	{
		head->prev = tmp;
	}

	if (m_size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		head = tmp;
	}

	m_size++;
}

void My_List::push_tail(Price* n_data)
{
	Elem* tmp = new Elem;
	tmp->next = 0;
	tmp->m_data = n_data;
	tmp->prev = tail;

	if (tail != NULL)
	{
		tail->next = tmp;
	}

	if (m_size == 0)
	{
		head = tail = tmp;
	}
	else
	{
		tail = tmp;
	}

	m_size++;
}

void My_List::remove(int index)
{
	//если параметр отсутствует или равен 0, то запрашиваем его
	/*if (index == 0)
	{
		cout << "Input position: ";
		cin >> index;
	}*/

	// Позиция от 1 до Count?
	if (index < 1 || index > m_size + 1)
	{
		throw "Incorrect position!";
		system("pause");
		//return;
	}

	//если добавляем не в конец и не в начало списка, то
	Elem* DelElem = head;
	for (int i = 0; i < index; i++)
	{
		DelElem = DelElem->next;
	}

	// Доходим до элемента, 
	// который предшествует
	Elem* PrevDel = DelElem->prev;
	Elem* NextDel = DelElem->next;

	//настройка связей
	if (PrevDel != NULL && m_size != 1)
	{
		PrevDel->next = NextDel;
	}
	if (NextDel != NULL && m_size != 1)
	{
		NextDel->next = PrevDel;
	}
	if (index == 1)
	{
		head = NextDel;
	}
	if (index == m_size)
	{
		tail = PrevDel;
	}

	delete DelElem;
	m_size--;
}

void My_List::insert(Price* n_data, int index = 0)
{
	//если параметр отсутствует или равен 0, то запрашиваем его
	if (index == 0)
	{
		push_tail(n_data);
		return;
	}

	// Позиция от 1 до Count?
	if (index < 1 || index > m_size + 1)
	{
		throw "Incorrect position!";
		system("pause");
		return;
	}

	// Если вставка в конец списка
	if (index == m_size + 1)
	{
		push_tail(n_data);
		return;
	}
	else if (index == 1)
	{
		push_head(n_data);
		return;
	}

	//если добавляем не в конец и не в начало списка, то
	Elem* NewElem = head;
	for (int i = 0; i < index; i++)
	{
		NewElem = NewElem->next;
	}

	// Доходим до элемента, 
	// который предшествует
	Elem* PrevNewElem = NewElem->prev;

	Elem* tmp = new Elem;

	//настройка связей
	if (PrevNewElem != NULL && m_size != 1)
	{
		PrevNewElem->next = tmp;
	}

	tmp->next = NewElem;
	tmp->prev = PrevNewElem;
	NewElem->prev = tmp;

	m_size++;
}

int My_List::get_size() { return m_size; }

void My_List::swap(Price* other, Price* another)
{
	Price* temp = other;
	other = another;
	another = temp;
}

void My_List::sort()
{
	Elem* one = new Elem;
	Elem* two = new Elem;

	for (int i = 0; i < m_size - 1; i++)
	{
		one = head;
		for (int j = 0; j < m_size - i - 1; j++)
		{
			two = one->next;
			if (one->m_data->get_shop().compare(two->m_data->get_shop()) < 0)
			{
				swap(one->m_data, two->m_data);
			}
			one = two;
			two = one->next;
		}
	}
}

void My_List::finding(string name)
{
	if (m_size == 0)
	{
		throw "There's nothing to find, the list is empty.";
		system("pause");
	}

	Elem* tmp;
	tmp = head;
	int shop_is_in = 0; //признак отстутствия введенного названия магазина
	//int name_shop = 0; //признак вывода названия магазина на экран

	for (int i = 0; i < m_size; i++)
	{
		if (tmp->m_data->get_shop().compare(name) == 0)
		{
			cout << tmp->m_data->get_item() << ", " << tmp->m_data->get_cost() << endl << endl;

			shop_is_in = 1;
		}
		tmp = tmp->next;
	}

	if (shop_is_in == 0)
	{
		throw "There's no inputtes shop.";
		system("pause");
	}
	//system("pause");
}