#pragma once
#include"node.h"
#include<assert.h>
template<typename T>
class list
{
public:
	list();
	~list();
	unsigned int DataFind(const T Data);
	void DataInsert(const T Data, const unsigned int Sign);
	inline void DataInsert_head(const T Data);
	inline void DataInsert_tail(const T Data);
	void DataDel(const unsigned int Sign);
	inline void DataDel_head();
	inline void DataDel_tail();
	void DataChange(const T Data, const unsigned int Sign);
	void ListPrint();
	void ListFormat();
	size_t size();

private:
	node<T>* HEAD;
	node<T>* TAIL;
	size_t LENTH;
};

template<typename T>
inline list<T>::list():
	HEAD(new node<T>),
	TAIL(new node<T>),
	LENTH(0)
{
	HEAD->ChangeNext(TAIL);
	TAIL->ChangePre(HEAD);
}

template<typename T>
inline list<T>::~list()
{
	while (HEAD->NodeNext() != TAIL)
	{
		node<T>* temp = HEAD->NodeNext();
		delete HEAD;
		HEAD = temp;
	}
	LENTH = 0;
}

template<typename T>
unsigned int list<T>::DataFind(const T Data)
{
	node<T>* ptr = HEAD->NodeNext();
	unsigned int count = 1;
	while (ptr != TAIL)
	{
		if (ptr->Datacmp(Data)) { return count; }
		ptr = ptr->NodeNext();
		count++;
	}
	return 0;
}

template<typename T>
void list<T>::DataInsert(const T Data, const unsigned int Sign)
{
	assert(Sign <= LENTH + 1);
	unsigned int count = 1;
	node<T>* temp = HEAD;
	while (count != Sign)
	{
		temp = temp->NodeNext();
		count++;
	}
	node<T>* point = new node<T>;
	node<T>* temp_n = temp->NodeNext();
	point->DataPut(Data);
	temp->ChangeNext(point);
	point->ChangePre(temp);
	temp_n->ChangePre(point);
	point->ChangeNext(temp_n);
	LENTH++;
}

template<typename T>
inline void list<T>::DataInsert_head(const T Data)
{
	HEAD->ChangePre(new node<T>);
	node<T>* temp = HEAD->NodePre();
	HEAD->DataPut(Data);
	temp->ChangeNext(HEAD);
	HEAD = temp;
	LENTH++;
}

template<typename T>
inline void list<T>::DataInsert_tail(const T Data)
{
	TAIL->ChangeNext(new node<T>);
	node<T>* temp = TAIL->NodeNext();
	TAIL->DataPut(Data);
	temp->ChangePre(TAIL);
	TAIL = temp;
	LENTH++;
}

template<typename T>
void list<T>::DataDel(const unsigned int Sign)
{
	assert(Sign <= LENTH);
	unsigned int count = 1;
	node<T>* temp = HEAD->NodeNext();
	while (count != Sign)
	{
		temp = temp->NodeNext();
		count++;
	}
	node<T>* temp_n = temp->NodeNext();
	node<T>* temp_p = temp->NodePre();
	temp_n->ChangePre(temp_p);
	temp_p->ChangeNext(temp_n);
	delete temp;
	temp = nullptr;
	LENTH--;
}

template<typename T>
inline void list<T>::DataDel_head()
{
	node<T>* temp = HEAD->NodeNext();
	HEAD->ChangeNext(temp->NodeNext());
	delete temp;
	temp = HEAD->NodeNext();
	temp->ChangePre(HEAD);
	LENTH--;
}

template<typename T>
inline void list<T>::DataDel_tail()
{
	node<T>* temp = TAIL->NodePre();
	TAIL->ChangePre(temp->NodePre());
	delete temp;
	temp = TAIL->NodePre();
	temp->ChangeNext(TAIL);
	LENTH--;
}

template<typename T>
inline void list<T>::DataChange(const T Data, const unsigned int Sign)
{
	assert(Sign <= LENTH);
	unsigned int count = 1;
	node<T>* temp = HEAD->NodeNext();
	while (count != Sign)
	{
		temp = temp->NodeNext();
		count++;
	}
	temp->DataPut(Data);
}

template<typename T>
void list<T>::ListPrint()
{
	node<T>* ptr = HEAD->NodeNext();
	while (ptr != TAIL)
	{
		ptr->DataOut();
		ptr = ptr->NodeNext();
	}
}

template<typename T>
inline void list<T>::ListFormat()
{
	while (HEAD->NodeNext() != TAIL)
	{
		node<T>* temp = HEAD->NodeNext();
		delete HEAD;
		HEAD = temp;
	}
	LENTH = 0;
}

template<typename T>
inline size_t list<T>::size()
{
	return LENTH;
}


