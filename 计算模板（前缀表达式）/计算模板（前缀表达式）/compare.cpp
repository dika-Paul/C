#include "compare.h"
#include<assert.h>

bool _judg(const char _signal)
{
	if (_signal == '+' || _signal == '-' || _signal == '*' || _signal == '/') { return true; }
	else if (_signal == '(' || _signal == ')') { return true; }
	else if (_signal >= 'a' && _signal <= 'z') { return false; }
	else if (_signal >= 'A' && _signal <= 'Z') { return false; }
	else
	{
		assert(false);
		return true;
	}
}

bool _cmp(const char _signal, const char _stdd)
{
	if (_signal == '+' || _signal == '-')
	{
		if (_stdd == '+' || _stdd == '-' || _stdd == ')') { return false; }
		else { return true; }
	}
	else
	{
		return false;
	}
}

