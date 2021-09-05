#pragma once

typedef int OSlenth;
typedef struct order_sheet {
	OSlenth* a;
	int size;
	int capability;
}OSL;

bool os_format(OSL* ptr);
// format the order sheet;
void os_cap_check(OSL* ptr);
// check does there is enough space to store the data
void os_insert(OSL* ptr, int sign, OSlenth data);
// insert the data in a specific place
void os_insert_head(OSL* ptr, OSlenth data);
// insert the data at the head
void os_intsert_end(OSL* ptr, OSlenth data);
// insert the data at the end
void os_del(OSL* ptr, int sign);
// del the data at the specific place
void os_del_head(OSL* ptr);
// del the data at the head
void os_del_end(OSL* ptr);
// del the data at the end
int os_find(OSL* ptr, OSlenth data);
// find the data and return the position
void os_print(OSL* ptr);
// print all the data
size_t os_size(OSL* ptr);
// find the size of array
void os_change(OSL* ptr, int sign, OSlenth data);
// change the data at the specific place
void os_destory(OSL* ptr);
// delet the whole order sheet;