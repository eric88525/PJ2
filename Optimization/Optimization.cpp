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
				for (auto j : cmp) {
					if (str[i - 1] == j || ('0' < str[i - 1] && str[i - 1] < '9')){
						str[i] = '_';
					break;
					}
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

string variableChange(string &ori, string x, string y)
{
	string result = ori;
	for (int i = 0; i < result.length();i++) {
		if (result[i]=='x') {
			result.erase(i,1);
			result.insert(i,x);
			i += x.length() - 1;
		}
		else if (result[i] == 'y') {
			result.erase(i, 1);
			result.insert(i, y);
			i += y.length() - 1;
		}
	}
	return result;
}

double cal(string equation, double x, double y)
{
	double result=0;
	vector<string> equ = IntoPost(equation);
	vector<double> stack;
	double l,r,temp;
	for (int i = 0; i < equ.size();i++) {
		//std::cout << equ[i];
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
			else if (equ[i]=="_") {
				temp = -1 * r;
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "sin") {	
				temp = sin(r*PI / 180);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "cos") {
				temp = cos(r*PI / 180);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "tan") {
				temp = tan(r*PI / 180);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "cot") {
				temp = 1/tan(r*PI / 180);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "sec") {
				temp = 1 / cos(r*PI / 180);
				stack.pop_back();
				stack.push_back(temp);
			}
			else if (equ[i] == "csc") {
				temp = 1 / sin(r*PI / 180);
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
double part_dx(string equation, double x, double y)
{
	return (cal(equation, x, y) - cal(equation, x - H, y)) / (H);
}
double part_dxx(string equation, double x, double y)
{
	return (cal(equation, x + H, y) + cal(equation, x - H, y) - (2.0*cal(equation, x, y))) / (H*H);
}
double part_dy(string equation, double x, double y)
{
	return (cal(equation, x, y) - cal(equation, x, y - H)) / (H);
}
double part_dyy(string equation, double x, double y)
{
	return (cal(equation, x, y + H) + cal(equation, x, y - H) - (2.0*cal(equation, x, y))) / (H*H);
}

double golden_search(double range_min, double range_max,string equation)
{
	//double x4;
	//if (x3 - x2 > x2 - x1) {    // b > a�A�k�b�϶����׸��j
	//	x4 = x2 + RESPHI * (x3 - x2);   // x4�w���b�k�b�϶�
	//}else {    // b <= a�A���b�϶����׸��j
	//	x4 = x2 - RESPHI * (x2 - x1);   // x4�w���b���b�϶�
	//}
	//if (abs(x3 - x1) < tau * (abs(x2) + abs(x4))) {    // �P�_�O�_�F�즬�ı���
	//	return (x3 + x1) / 2;   // �F�즬�ı���A���϶����ת��@�b�@�����p���I��X
	//}
	////cout << "x1=" << x1 << "  x2=" << x2 << "  x3=" << x3 << "\n";
	//if (x4 != x2) {
	//	if (cal(equation, x4, 0) < cal(equation, x2, 0)) {    // x4�I���禡�Ȧp�Ϥ�f4b�ҥܮ�
	//		if (x3 - x2 > x2 - x1) {    // b > a�A�k�b�϶����׸��j
	//			return golden_search(x2, x4, x3, equation);  // �Hx2�Ax4�Ax3�@���s�T�I�A�~��j�M
	//		}
	//		else {    // b <= a�A���b�϶����׸��j
	//			return golden_search(x1, x4, x2, equation);  // �Hx1�Ax4�Ax2�@���s�T�I�A�~��j�M
	//		}
	//	}
	//	else {    // x4�I���禡�Ȧp�Ϥ�f4a�ҥܮ�
	//		if (x3 - x2 > x2 - x1) {    // b > a�A�k�b�϶����׸��j
	//			return golden_search(x1, x2, x4, equation);  // �Hx1�Ax2�Ax4�@���s�T�I�A�~��j�M
	//		}
	//		else {  // b <= a�A���b�϶����׸��j
	//			return golden_search(x4, x2, x3, equation);  // �Hx4�Ax2�Ax3�@���s�T�I�A�~��j�M
	//		}
	//	}
	//}
	//
	int i, n;
	double d, x1, x2;

	//printf("i xl f(xl) x2 f(x2) x1 f(x1) xu f(xu) d\n");
	for (i = 1; i <= 100; i++) {
		d = 0.61803*(range_max - range_min);
		x1 = range_min + d;
		x2 = range_max - d;
		if (abs(cal(equation, x2, 0) - cal(equation, x1, 0)) < 1e-8) {
			return x2;
		}
		if (cal(equation, x2, 0) > cal(equation, x1, 0)) {    /* ���k�� */
			range_min = x2;
			x2 = x1;
		}
		else {              /* ������ */
			range_max = x1;
			x1 = x2;
		}
	}
	for (i = 1; i <= 100; i++) {
		d = 0.61803*(range_max - range_min);
		x1 = range_min + d;
		x2 = range_max - d;
		if (abs(cal(equation, x2, 0) - cal(equation, x1, 0)) < 1e-8) {
			return x2;
		}
		if (cal(equation,x2,0) > cal(equation,x1,0)) {    /* ���k�� */
			range_min = x2;
			x2 = x1;
		}
		else {              /* ������ */
			range_max = x1;
			x1 = x2;
		}
	}
}

void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output)
{
	double alpha=golden_search(intervalX1,intervalX2,equation);	
	Output->Text += "[x] = [" + alpha + "]" + nL;
	Output->Text += "min = " + cal(equation,alpha,0);
}

void powell_method(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output)
{
	double prevalue = INFINITY;
	vector<double> a;
	vector<Vector> Xi(1);
	vector<double>datax = { 1,0 };
	vector<double>datay = { 0,1 };
	vector<Vector> s;
	s.push_back(Vector(datax));
	s.push_back(Vector(datay));
	Xi[0].Data.push_back(iniX);
	Xi[0].Data.push_back(iniY);
	int i=1, j=1;
	bool run = true;
	while (run) {
		for (int i = 1; i <= 3 && j<100;i++) {
			if (i == 3) {
				Vector Sbuffer = a[0] * s[0] + a[1] * s[1];
				s.push_back(Sbuffer);
			}
			string bufferX = "(" + std::to_string(Xi[i-1].Data[0]) + "+x*" + std::to_string(s[i-1].Data[0]) + ")";
			string bufferY = "(" + std::to_string(Xi[i-1].Data[1]) + "+x*" + std::to_string(s[i-1].Data[1]) + ")";
			string bufferStr = variableChange(equation, bufferX, bufferY);
			double left, right, mid;
			left = (intervalX1 - Xi[i - 1].Data[0]) > (intervalY1 - Xi[i - 1].Data[1]) ?
				(intervalX1 - Xi[i - 1].Data[0]) : (intervalY1 - Xi[i - 1].Data[1]);
			right = (intervalX2 - Xi[i - 1].Data[0]) > (intervalY2 - Xi[i - 1].Data[1]) ?
				(intervalY2 - Xi[i - 1].Data[1]) : (intervalX2 - Xi[i - 1].Data[0]);
			double abuff = golden_search(left, right, bufferStr);
			a.push_back(abuff);
			Vector x = Xi[i - 1];
			x = x+ a[i - 1] * s[i-1];
			double resultValue = cal(equation, x.Data[0], x.Data[1]);
			cout << "  Left = " << left << "  Right = " << right <<" a= "<<abuff<< "\n";
			cout << "  i= " << i << "  j= " << j << " Vec = " << x.Data[0] << " , " << x.Data[1] << " V = " << resultValue << "\n";
			if (abs(resultValue - prevalue )<lim || (x*x).Data[0] < lim     ) {
				//cout << x.Data[0] << "   " << x.Data[1];
				
				cout << "final is_________" << resultValue<<"\n";
				//cout << resultValue << "\n";
				run = false;
				return;
			}
			
			Xi.push_back(x);
			prevalue = resultValue;
		}
		Vector vb = Xi[3];
		Xi.clear();
		Xi.push_back(vb);
		s.erase(s.begin());
		a.clear();
		j++;
	}
}
