#pragma once

#include<iostream>

using namespace std;

class Matrix
{
	friend Matrix operator+(const Matrix& _first, const Matrix& _second);
	friend Matrix operator-(const Matrix& _first, const Matrix& _second);
	friend Matrix operator*(const Matrix& _first, const Matrix& _second);
	friend ostream& operator<<(ostream& _out, const Matrix& _temp);
	friend istream& operator>>(istream& _in, Matrix& _temp);
	
public:
	Matrix();
	Matrix(const unsigned int ROW, const unsigned int COL);
	Matrix(const Matrix& T);
	~Matrix();
	void SetUnit();
	void MatrixTranspose();
	Matrix& operator=(const Matrix& _temp);

private:
	int** _Array;
	size_t _ROW;
	size_t _COL;
};

