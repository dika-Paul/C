#include "list.h"
#include<cstdlib>
#include<assert.h>
#include<iostream>

bool os_format(OSL* ptr)
{
	bool judg = false;
	if (ptr)
	{
		ptr->a = nullptr;
		ptr->capability = ptr->size = 0;
		judg = true;
	}
	return judg;
}

void os_cap_check(OSL* ptr)
{
	if (ptr->size == ptr->capability)
	{
		int new_space = ptr->capability == 0 ? 4 : ptr->capability * 2;
		OSlenth* temp = (OSlenth*)realloc(ptr->a, new_space * sizeof(OSlenth));
		assert(temp != nullptr);
		ptr->a = temp;
		ptr->capability = new_space;
	}
}

void os_insert(OSL* ptr, int sign, OSlenth data)
{
	os_cap_check(ptr);
	int end = ptr->size;
	int start = sign;
	while (start <= end)
	{
		ptr->a[end] = ptr->a[end - 1];
		end--;
	}
	ptr->a[sign - 1] = data;
	ptr->size++;
}

void os_insert_head(OSL* ptr, OSlenth data)
{
	os_cap_check(ptr);
	os_insert(ptr, 1, data);
}

void os_intsert_end(OSL* ptr, OSlenth data)
{
	os_cap_check(ptr);
	os_insert(ptr, ptr->size+1, data);
}

void os_del(OSL* ptr, int sign)
{
	assert(ptr);
	assert(sign <= ptr->size);
	int end = ptr->size-1;
	int start = sign - 1;
	while (start <= end)
	{
		ptr->a[start] = ptr->a[start + 1];
		start++;
	}
	ptr->size--;
}

void os_del_head(OSL* ptr)
{
	os_del(ptr, 1);
}

void os_del_end(OSL* ptr)
{
	os_del(ptr, ptr->size);
}

int os_find(OSL* ptr, OSlenth data)
{
	assert(ptr);
	for (int i = 0; i < ptr->size; i++)
	{
		if (ptr->a[i] == data) { return i+1; }
	}
	return -1;
}

void os_print(OSL* ptr)
{
	assert(ptr);
	for (int i = 0; i < ptr->size; i++)
	{
		std::cout << ptr->a[i];
	}
}

size_t os_size(OSL* ptr)
{
	return ptr->size;
}

void os_change(OSL* ptr, int sign, OSlenth data)
{
	assert(ptr);
	assert(sign <= ptr->size);
	ptr->a[sign] = data;
}

void os_destory(OSL* ptr)
{
	assert(ptr);
	if (ptr->a)
	{
		free(ptr->a);
		ptr->a = nullptr;
	}
	ptr->size = ptr->capability = 0;
}
