#pragma once
#include<iostream>

template<typename T>
class node
{
public:
	node();
	~node();
	node<T>* NodeNext();
	node<T>* NodePre();
	void ChangeNext(node<T>* ptr);
	void ChangePre(node<T>* ptr);
	inline void DataPut(const T Data);
	inline bool Datacmp(const T Data);
	inline void DataOut();

private:
	node<T>* PRE;
	node<T>* NEXT;
	T* DATA;
};

template<typename T>
inline node<T>::node() :
	PRE(nullptr),
	NEXT(nullptr),
	DATA(new T)
{}

template<typename T>
inline node<T>::~node()
{
	PRE = nullptr;
	NEXT = nullptr;
	delete DATA;
	DATA = nullptr;
}

template<typename T>
inline node<T>* node<T>::NodeNext()
{
	return NEXT;
}

template<typename T>
inline node<T>* node<T>::NodePre()
{
	return PRE;
}

template<typename T>
inline void node<T>::ChangeNext(node<T>* ptr)
{
	NEXT = ptr;
}

template<typename T>
inline void node<T>::ChangePre(node<T>* ptr)
{
	PRE = ptr;
}

template<typename T>
inline void node<T>::DataPut(const T Data)
{
	*DATA = Data;
}

template<typename T>
inline bool node<T>::Datacmp(const T Data)
{
	bool judg;
	judg = (*DATA == Data ? true : false);
	return judg;
}

template<typename T>
inline void node<T>::DataOut()
{
	std::cout << *DATA;
}
