#include "Optimization.h"
#include<iostream>
using namespace std;
int priority(string op) {
	switch (op[0]) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '_': case '^': return 3; // �t�� ����
	case '$': return 4;			//�T�����
	default:            return 0;
	}
}
vector<string> IntoPost(string str) {

	for (int i = 0; i < str.length();i++) {
		if (str[i] == '-') {
			if (i == 0) str[i] = '_';
			else{
				string cmp = "(+-*/^";
				for (auto j:cmp) {
					if (str[i - 1] == j)str[i] = '_';
					break;
				}
			}
		}
	}
	vector<string> stack;
	vector<string> postfix ;
	bool isV = false;
	for (int i = 0; i < str.length(); i++) {
		string temps = "";
		
		switch (str[i]) {
		case '(':     // �B��l���| 	
			stack.push_back("(");
			isV = false;
			break;
		case '+': case '-': case '*':case '/': case '^':case '_':
			temps = str[i];
			while (stack.size() && priority(stack[stack.size() - 1]) >= priority(temps)      ) {
				postfix.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
			stack.push_back(temps); // �s�J���| 
			isV = false;
			break;
		case ')':
			while (stack[stack.size() - 1] != "(") { // �J ) ��X�� ( 
				postfix.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
			if (stack[stack.size() - 1] == "(") stack.pop_back();
			isV = false;
			break;
		case 'x':  // �B�⤸������X 
			
			postfix.push_back("x");
			isV = false;
			break;
		case 'y':  // �B�⤸������X 
			postfix.push_back("y");
			isV = false;
			break;
		case 's':  //  
			temps = temps.assign(str,i,3);
			if (temps == "sin" || temps == "sec") {
				stack.push_back(temps);
				i += 2;
			}
			isV = false;
			break;
		case 'c':  //  
			temps = temps.assign(str, i, 3);
			if (temps == "cos" || temps == "cot" || temps == "csc") {
				stack.push_back(temps);
				i += 2;
			}
			isV = false;
			break;
		case 't':  //  
			temps = temps.assign(str, i, 3);
			if (temps == "tan" ) {
				stack.push_back(temps);
				i += 2;
			}
			isV = false;
			break;

		default:  // �B�⤸������X
			if (!isV) {
				temps = str[i];
				postfix.push_back(temps);
				isV = true;
			}
			else {
				postfix[postfix.size()-1].push_back(str[i]);
			}
			break;
		}
	}
	for (int i = stack.size() - 1; i >= 0;i--) {
		postfix.push_back(stack[i]);
	}	
	return postfix;
}

double cal(string equation, double x, double y)
{
	double result=0;
	vector<string> equ = IntoPost(equation);
	vector<double> stack;
	double l,r,temp;
	for (int i = 0; i < equ.size();i++) {
		std::cout << equ[i];
		if (isNumber(equ[i])) {
			if (equ[i] == "x") {
				stack.push_back(x);
			}
			else if (equ[i] == "y") {
				stack.push_back(y);
			}
			else {
				stack.push_back(stod(equ[i]));
			}
		}
		else {
			if(stack.size())r = stack[stack.size() - 1];
			else break;
			if (equ[i] == "+") {
				l = stack[stack.size() - 2];
				temp = l + r;
				stack.pop_back();
				stack.pop_back();
				stack.push_back(temp);
			}else if (equ[i] == "-") {
				l = stack[stack.size() - 2];
				temp = l - r;
				stack.pop_back();
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "*") {
				l = stack[stack.size() - 2];
				temp = l * r;
				stack.pop_back();
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "/") {
				l = stack[stack.size() - 2];
				temp = l / r;
				stack.pop_back();
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "^") {
				l = stack[stack.size() - 2];
				temp = pow(l , r);
				stack.pop_back();
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "sin") {	
				temp = sin(r);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "cos") {
				temp = cos(r);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "tan") {
				temp = tan(r);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "cot") {
				temp = 1/tan(r);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "sec") {
				temp = 1 / cos(r);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "csc") {
				temp = 1 / sin(r);
				stack.pop_back();
				stack.push_back(temp);
			}
		}
	}
	return temp;
}
bool isNumber(string x) {
	if (x == "x" || x == "y")return true;
	for (auto i:x) {
		if ((i<'0' || i>'9') && i!='.') {
			return false;
		}
	}
	return true;
}
double golden_search(double x1, double x2, double x3, double x4)
{
	
	if (x3 - x2 > x2 - x1) {    // b > a�A�k�b�϶����׸��j
		x4 = x2 + RESPHI * (x3 - x2);   // x4�w���b�k�b�϶�
	}
	else {    // b <= a�A���b�϶����׸��j
		x4 = x2 - RESPHI * (x2 - x1);   // x4�w���b���b�϶�
	}
	if (abs(x3 - x1) < tau * (abs(x2) + abs(x4))) {    // �P�_�O�_�F�즬�ı���
		return (x3 + x1) / 2;   // �F�즬�ı���A���϶����ת��@�b�@�����p���I��X
	}









	return 0.0;
}
