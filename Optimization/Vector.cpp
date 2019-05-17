#include"Vector.h"
#include"Error.h"
Vector::Vector(std::vector<double> data)
{
	this->Data = data;
}

Vector::Vector(std::string name, std::vector<double> data) {
	this->Name = name;
	this->Data = data;
}

System::String^ Vector::getResult()
{
	System::String^ outputTemp = gcnew System::String(Name.c_str()) + " = ";
	outputTemp += "[";
	for (unsigned int j = 0; j < Data.size(); j++)
	{
		System::String^ buff = Data[j].ToString();

		//if (buff->Length > 8)buff = buff->Substring(0, 8);
		outputTemp += buff;
		if (j != Data.size() - 1)
			outputTemp += ",";
	}
	outputTemp += "]" + System::Environment::NewLine;
	return outputTemp;
}



const Vector operator+(const Vector &x, const Vector &y) {
	
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw V_rankdiff;
	}
	else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] + y.Data[i]);
		}
	}
	return Vector(data);
}

const Vector operator-(const Vector &x, const Vector &y) {
	int rankdiff;
	std::vector<double> data;
	if (x.Data.size() != y.Data.size()) {
		throw V_rankdiff;
	}
	else {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] - y.Data[i]);
		}
	}
	return Vector(data);
}


const Vector operator*(const Vector &x, const Vector &y) {

	int rankdiff;
	std::vector<double> data;
	if (x.Data.size() == 1) {
		for (int i = 0; i < y.Data.size(); i++) {
			data.push_back(y.Data[i] * x.Data[0]);
		}
	}
	else if (y.Data.size() == 1) {
		for (int i = 0; i < x.Data.size(); i++) {
			data.push_back(x.Data[i] * y.Data[0]);
		}
	}
	else if (x.Data.size() != y.Data.size()) {
		throw V_rankdiff;
	}
	else {
		double sum = 0;
		for (int i = 0; i < x.Data.size(); i++) {
			sum += y.Data[i] * x.Data[i];
		}
		data.push_back(sum);
	}
	return Vector(data);
}

const Vector operator*( double v, const Vector & x)
{
	std::vector<double> data = x.Data;
	for (auto & i : data) {
		i *= v;
	}
	return Vector(data);
}

const double norm(const Vector &x) {
	double sum = 0.0;
	std::vector<double> data;
	for (int i = 0; i < x.Data.size(); i++) {
		sum += std::abs(pow(x.Data[i], 2));
	}
	return sqrt(sum);
}
const Vector normalization(const Vector &x) {
	double sum = 0;
	std::vector<double>data;
	for (auto i : x.Data) {
		sum += i * i;
	}
	sum = sqrt(sum);
	data = x.Data;
	for (auto &i : data) {
		i /= sum;
	}
	return Vector(data);
}


const Vector crossProduct(const Vector & x, const Vector & y)
{
	double i = x.Data[1] * y.Data[2] - y.Data[1] * x.Data[2],
		j = x.Data[0] * y.Data[2] - y.Data[0] * x.Data[2],
		k = x.Data[0] * y.Data[1] - y.Data[0] * x.Data[1];
	std::vector<double>data = { i,j,k };
	return Vector(data);
}

const Vector component(const Vector & x, const Vector & y)
{
	Vector vec;
	vec = x * y;
	double n;
	n = norm(y);
	vec.Data[0] /= n;
	//return  Vector(vec.Data);
	return vec;
}

const Vector projection(const Vector & x, const  Vector & y)
{
	Vector vec;
	vec = component(x, y);
	vec = vec * normalization(y);
	return vec;
}

const double area(const Vector & x, const Vector & y)
{

	double c = norm(x);
	double a = component(x, y).Data[0];
	double b = sqrt(c*c - a * a);
	double area = norm(y)*b / 2;
	return area;

}
const Vector pN(const Vector & x, const Vector & y)
{
	return crossProduct(x, y);
}
const bool isParallel(const Vector & x, const Vector & y)
{
	if (x.Data.size() != y.Data.size())return false;
	double rate = -8763.30678;
	for (int i = 0; i < x.Data.size(); i++) {
		if (!(x.Data[i] == 0 || y.Data[i] == 0)) {
			if (rate == -8763.30678) {
				rate = y.Data[i] / x.Data[i];
			}
			else if ((abs(rate*x.Data[i] - y.Data[i]) > misRange)) {
				return false;
			}
		}
	}
	if (rate != -8763.30678)return true;
	else return false;
}

const bool isOrthogonal(const Vector & x, const Vector & y)
{
	double sum;
	for (int i = 0; i < x.Data.size(); i++) {
		sum += x.Data[i] * y.Data[i];
	}
	if (!sum)return true;
	return false;
}

const double angle(const Vector & x, const Vector & y)
{
	Vector vec;
	double result;
	vec = x * y;
	for (auto &i : vec.Data) {
		i = i / (norm(x)*norm(y));
	}
	result = acos(vec.Data[0]) * 180.0 / PI;
	return result;
}

const bool isLI(const Vector & x, const Vector & y)
{
	if (!isParallel(x, y)) {
		return true;
	}
	return false;
}

const std::vector<Vector> Ob(std::vector<Vector>list)
{
	/*std::vector<Vector>list;
	va_list ptr;
	va_start(ptr, count);
	for (int i = 0; i < count; i++) {
		Vector buff  = va_arg(ptr, Vector);
		list.push_back(buff);
	}*/
	list[0] = normalization(list[0]);
	for (int i = 0; i < list.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			list[i] = list[i] - projection(list[i], list[j]);
		}
		list[i] = normalization(list[i]);
	}
	//va_end(ptr);
	return list;
}