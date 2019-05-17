#pragma once
#include <vector>
#include <algorithm>
#define _USE_MATH_DEFINES 
#include<math.h>
#define misRange 0.000000001
#include"Error.h"
class Matrix {
public:
	std::string Name = "";
	std::vector<std::vector<double>> Data;
	int row;
	int col;
	Matrix();
	Matrix(std::vector<std::vector<double>> data);
	System::String^ getResult();
	friend const Matrix operator+(const Matrix &x, const Matrix &y);
	friend const Matrix operator-(const Matrix &x, const Matrix &y);
	friend const Matrix operator*(const Matrix &x, const Matrix &y);
	friend const int rank(Matrix x);
	friend const Matrix transpose(const Matrix &x);
	friend const Matrix operator/(Matrix x, Matrix y);	//linear system
	friend const double determinants(Matrix x);
	friend const Matrix inverse(Matrix x);
	friend const Matrix Adj(const Matrix &x);
	friend const Matrix pm(const Matrix &x, double&);
	friend const Matrix eigen(const Matrix &x,std::vector<double>&);
	friend const Matrix LeastSquare(const Matrix &x, const Matrix &y);
	friend const std::vector<Matrix> rref( Matrix x);
};
