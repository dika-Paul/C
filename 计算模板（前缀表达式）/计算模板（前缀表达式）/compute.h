#pragma once
#pragma once

#include<string>
#include<stack>
#include<iostream>
#include<assert.h>
#include"compare.h"
using namespace std;

template<typename T>
struct _computing_data
{
	T _data;
	char _signal;
	bool _which;
	_computing_data& operator=(const _computing_data& _temp)
	{
		_data = _temp._data;
		_signal = _temp._signal;
		_which = _temp._which;
		return *this;
	}
};

template<typename T>
void _expression_translate(stack<_computing_data<T>>& _final, const string _str)
{
	stack<char> _temp1;
	stack<_computing_data<T>> _temp2;
	for (int i = _str.size() - 1; i >= 0; i--)
	{
		if (_judg(_str[i]))
		{
			switch (_str[i])
			{
			case ')':
				_temp1.push(_str[i]);
				break;
			case '(':
				while (_temp1.top() != ')')
				{
					_computing_data<T> _temp;
					_temp._signal = _temp1.top();
					_temp._which = true;
					_temp1.pop();
					_temp2.push(_temp);
				}
				_temp1.pop();
				break;
			default:
					while (!_temp1.empty() && _cmp(char(_str[i]), _temp1.top()))
					{
						_computing_data<T> _temp;
						_temp._signal = _temp1.top();
						_temp._which = true;
						_temp1.pop();
						_temp2.push(_temp);
					}
				_temp1.push(_str[i]);
				break;
			}
		}
		else
		{
			_computing_data<T> _temp;
			cin >> _temp._data;
			_temp._which = false;
			_temp2.push(_temp);
		}
	}
	while (!_temp1.empty())
	{
		_computing_data<T> _temp;
		_temp._signal = _temp1.top();
		_temp._which = true;
		_temp1.pop();
		_temp2.push(_temp);
	}
	while (!_temp2.empty())
	{
		_final.push(_temp2.top());
		_temp2.pop();
	}
}

template<typename T>
T Compute(string _str)
{
	stack<_computing_data<T>> _final_expression;
	_expression_translate(_final_expression, _str);
	stack<T> _operator_expression;
	while (!_final_expression.empty())
	{
		_computing_data<T> _temp = _final_expression.top();
		_final_expression.pop();
		if (_temp._which)
		{
			T _Data;
			switch (_temp._signal)
			{
			case '+':
				_Data = _operator_expression.top();
				_operator_expression.pop();
				_Data = _Data + _operator_expression.top();
				_operator_expression.pop();
				_operator_expression.push(_Data);
				break;
			case '-':
				_Data = _operator_expression.top();
				_operator_expression.pop();
				_Data = _Data - _operator_expression.top();
				_operator_expression.pop();
				_operator_expression.push(_Data);
				break;
			case '*':
				_Data = _operator_expression.top();
				_operator_expression.pop();
				_Data = _Data * _operator_expression.top();
				_operator_expression.pop();
				_operator_expression.push(_Data);
				break;
			case '/':
				_Data = _operator_expression.top();
				_operator_expression.pop();
				_Data = _Data / _operator_expression.top();
				_operator_expression.pop();
				_operator_expression.push(_Data);
				break;
			default:
				break;
			}
		}
		else
		{
			_operator_expression.push(_temp._data);
		}
	}
	return _operator_expression.top();
}