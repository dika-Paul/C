#include"Matrix.h"
#define FOR(a,b,c) for(unsigned int (a)=(b); (a)<(c); (a)++)

#include<iostream>
#include<assert.h>
#include<iomanip>

using namespace std;

inline Matrix::Matrix() :
	_Array(nullptr),
	_ROW(0),
	_COL(0)
{
}

inline Matrix::Matrix(const unsigned int ROW, const unsigned int COL)
{
	_Array = new int*[ROW];
	FOR(i, 0, ROW)	{ *(_Array + i) = new int[COL]; }
	FOR(i, 0, ROW)
	{
		FOR(j, 0, COL)
		{
			_Array[i][j] = 0;
		}
	}
	_ROW = ROW;
	_COL = COL;
}

inline Matrix::Matrix(const Matrix& T)
{
	_ROW = T._ROW;
	_COL = T._COL;
	_Array = new int* [_ROW];
	FOR(i, 0, _ROW) { *(_Array + i) = new int[_COL]; }
	FOR(i, 0, _ROW)
	{
		FOR(j, 0, _COL)
		{
			_Array[i][j] = T._Array[i][j];
		}
	}
}

inline Matrix::~Matrix()
{
	FOR(i, 0, _ROW) { delete[] _Array[i]; }
	delete[] _Array;
	_ROW = 0;
	_COL = 0;
}

void Matrix::SetUnit()
{
	assert(_ROW != _COL);
	FOR(i, 0, _ROW) { _Array[i][i] = 1; }
}

void Matrix::MatrixTranspose()
{
	FOR(i, 0, _ROW)
	{
		FOR(j, i, _COL)
		{
			swap(_Array[i][j], _Array[j][i]);
		}
	}
}

Matrix& Matrix::operator=(const Matrix& _temp)
{
	_ROW = _temp._ROW;
	_COL = _temp._COL;
	_Array = new int* [_ROW];
	FOR(i, 0, _ROW) { *(_Array + i) = new int[_COL]; }
	FOR(i, 0, _ROW)
	{
		FOR(j, 0, _COL)
		{
			_Array[i][j] = _temp._Array[i][j];
		}
	}
	return *this;
}

Matrix operator+(const Matrix& _first, const Matrix& _second)
{
	assert((_first._ROW == _second._ROW) && (_first._COL == _second._COL));
	size_t ROW = _first._ROW;
	size_t COL = _first._COL;
	Matrix _temp(_first);
	FOR(i, 0, ROW)
	{
		FOR(j, 0, COL)
		{
			_temp._Array[i][j] += _second._Array[i][j];
		}
	}
	return _temp;
}

Matrix operator-(const Matrix& _first, const Matrix& _second)
{
	assert((_first._ROW == _second._ROW) && (_first._COL == _second._COL));
	size_t ROW = _first._ROW;
	size_t COL = _first._COL;
	Matrix _temp(_first);
	FOR(i, 0, ROW)
	{
		FOR(j, 0, COL)
		{
			_temp._Array[i][j] -= _second._Array[i][j];
		}
	}
	return _temp;
}

Matrix operator*(const Matrix& _first, const Matrix& _second)
{
	assert(_first._COL == _second._ROW);
	size_t _lenth = _first._COL;
	Matrix _temp(_first._ROW, _second._COL);
	FOR(i, 0, _temp._ROW)
	{
		FOR(j, 0, _temp._COL)
		{
			int num = 0;
			FOR(k, 0, _lenth)
			{
				num += (_first._Array[i][k] * _second._Array[k][j]);
			}
			_temp._Array[i][j] = num;
		}
	}
	return _temp;
}

ostream& operator<<(ostream& _out, const Matrix& _temp)
{
	_out << setw(4) << " ";
	FOR(i, 0, _temp._COL) { _out << setw(4) << i + 1; }
	_out << endl;
	_out << endl;
	FOR(i, 0, _temp._ROW)
	{
		_out << setw(4) << i + 1;
		FOR(j, 0, _temp._COL)
		{
			_out << setw(4) << _temp._Array[i][j];
		}
		_out << endl;
		_out << endl;
	}
	return _out;
}

istream& operator>>(istream& _in, Matrix& _temp)
{
	FOR(i, 0, _temp._ROW)
	{
		FOR(j, 0, _temp._COL)
		{
			_in >> _temp._Array[i][j];
		}
	}
	return _in;
}
