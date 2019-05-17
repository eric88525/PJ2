#pragma once
#define PI 3.14159265
#define misRange 0.000000001
#include<vector>
class Vector
{
public:
	std::string Name = "";
	std::vector<double> Data;
	Vector() {};
	Vector(std::vector<double> data);
	Vector(std::string name, std::vector<double> data);
	System::String^ getResult();
	friend const Vector operator+(const Vector &x, const Vector &y);
	friend const Vector operator-(const Vector &x, const Vector &y);
	friend const Vector operator*(const Vector &x, const Vector &y);
	friend const Vector operator*(double v, const Vector &x);
	friend const double norm(const Vector &x);
	friend const Vector normalization(const Vector &x);
	friend const Vector crossProduct(const Vector &x, const Vector &y);
	friend const Vector component(const Vector &x, const Vector &y);
	friend const Vector projection(const Vector &x, const Vector &y);
	friend const double area(const Vector &x, const Vector &y);
	friend const bool isParallel(const Vector &x, const Vector &y);
	friend const bool isOrthogonal(const Vector &x, const Vector &y);
	friend const double angle(const Vector &x, const Vector &y);
	friend const Vector pN(const Vector &x, const Vector &y);
	friend const bool isLI(const Vector &x, const Vector &y);
	friend const std::vector<Vector> Ob(std::vector<Vector>);
};