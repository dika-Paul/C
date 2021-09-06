#pragma once
#include<cstdlib>
#include<iostream>
#include<assert.h>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();
	inline void CapabilityCheck();//check the storage remain
	void DataInsert(const T Data, const unsigned int sign);//put data
	inline void DataInsert_first(const T Data);
	inline void DataInsert_end(const T Data);
	void DataDel(const unsigned int sign);//del data
	inline void DataDel_head();
	inline void DataDel_end();
	int Datafind(const T Data);//find the data
	void Dataprint();//print all data
	inline size_t A_size();//return Size
	inline void ArrayFormat();

private:
	T* Array;// if you use pointer you can use Array = new T, if not don't use new T the Array will creat twice;
	size_t Capability;
	size_t Size;
};

template<typename T>
inline List<T>::List()
{
	Array = nullptr;
	Capability = Size = 0;
}

template<typename T>
inline List<T>::~List()
{
	if (Array) { delete[] Array; }
	Array = nullptr;
	Capability = Size = 0;
}

template<typename T>
inline void List<T>::CapabilityCheck()
{
	if (Size == Capability)
	{
		size_t NewCap = (Capability == 0 ? 4 : Capability * 2);
		T* temp = new T[NewCap];
		memcpy(temp, Array, Capability * sizeof(T));
		delete[] Array;
		Array = temp;
		Capability = NewCap;
	}
}

template<typename T>
void List<T>::DataInsert(const T Data, const unsigned int sign)
{
	CapabilityCheck();
	assert(sign <= Size + 1 && sign > 0);
	int end = Size;
	int start = sign;
	while (end >= start)
	{
		Array[end] = Array[end - 1];
		end--;
	}
	Array[sign - 1] = Data;
	Size++;
}

template<typename T>
inline void List<T>::DataInsert_first(const T Data)
{
	DataInsert(Data, 1);
}

template<typename T>
inline void List<T>::DataInsert_end(const T Data)
{
	DataInsert(Data, Size + 1);
}

template<typename T>
void List<T>::DataDel(const unsigned int sign)
{
	assert(sign <= Size + 1 && sign > 0);
	int end = Size;
	int start = sign;
	while (start <= end)
	{
		Array[start - 1] = Array[start];
		start++;
	}
	Size--;
}

template<typename T>
inline void List<T>::DataDel_head()
{
	DataDel(1);
}

template<typename T>
inline void List<T>::DataDel_end()
{
	DataDel(Size);
}

template<typename T>
inline size_t List<T>::A_size()
{
	return Size;
}

template<typename T>
inline void List<T>::ArrayFormat()
{
	if (Array) { delete[] Array; }
	Array = nullptr;
	Capability = Size = 0;
}

template<typename T>
int List<T>::Datafind(const T Data)
{
	for (unsigned int i = 0; i < Size; i++)
	{
		if (Array[i] == Data) { return i + 1; }
	}
	return -1;
}

template<typename T>
void List<T>::Dataprint()
{
	for (unsigned int i = 0; i < Size; i++)
	{
		cout << Array[i];
	}
}
