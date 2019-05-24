#include "Optimization.h"
#include<iostream>
#define DEBUG
using namespace std;
int priority(string op) {
	string x = "sin cos tan cot sec csc";
	if (x.find(op) != x.npos) 
		return 4;

	switch (op[0]) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '_': case '^': return 3; // 負號 次方
	case '$': return 4;			//三角函數
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
					if (str[i - 1] == j ){
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
		case '(':     // 運算子堆疊 	
			stack.push_back("(");
			isV = false;
			break;
		case '+': case '-': case '*':case '/': case '^':case '_':
			temps = str[i];
			while (stack.size() && priority(stack[stack.size() - 1]) >= priority(temps)      ) {
				postfix.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
			stack.push_back(temps); // 存入堆疊 
			isV = false;
			break;
		case ')':
			while (stack[stack.size() - 1] != "(") { // 遇 ) 輸出至 ( 
				postfix.push_back(stack[stack.size() - 1]);
				stack.pop_back();
			}
			if (stack[stack.size() - 1] == "(") stack.pop_back();
			isV = false;
			break;
		case 'x':  // 運算元直接輸出 
			
			postfix.push_back("x");
			isV = false;
			break;
		case 'y':  // 運算元直接輸出 
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

		default:  // 運算元直接輸出
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
				if (r == 0.5)temp = sqrt(l);
				else temp = pow(l , r);
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
double part_dx(string equation, double x, double y)
{
	return (cal(equation, x+H, y) - cal(equation, x - H, y)) / (2.0*(H));
}
double part_dxx(string equation, double x, double y)
{
	return (cal(equation, x + H, y) + cal(equation, x - H, y) - (2.0*cal(equation, x, y))) / (H*H);
}
double part_dy(string equation, double x, double y)
{
	return (cal(equation, x, y + H) - cal(equation, x, y-H )) / (2.0*(H));
}
double part_dyy(string equation, double x, double y)
{
	return (cal(equation, x, y + H) + cal(equation, x, y - H) - (2.0*cal(equation, x, y))) / (H*H);
}
double Golden_Search(double range_min, double range_max, string equation)
{
	double zone,min = INFINITY,vmin;
	zone = fabs(range_max - range_min) / 5;
	
	for (double i = 0; i < 5;i++) {
		double v = (golden_search(range_min+i*zone,range_min+(i+1)*zone,equation));
		if (cal(equation, v, 0) < min) {
			min = cal(equation, v, 0);
			vmin = v;
		}
	}
	return vmin;
}

double golden_search(double range_min, double range_max,string equation)
{
	//double x4;
	//if (x3 - x2 > x2 - x1) {    // b > a，右半區間長度較大
	//	x4 = x2 + RESPHI * (x3 - x2);   // x4安插在右半區間
	//}else {    // b <= a，左半區間長度較大
	//	x4 = x2 - RESPHI * (x2 - x1);   // x4安插在左半區間
	//}
	//if (abs(x3 - x1) < tau * (abs(x2) + abs(x4))) {    // 判斷是否達到收斂條件
	//	return (x3 + x1) / 2;   // 達到收斂條件，取區間長度的一半作為極小值點輸出
	//}
	////cout << "x1=" << x1 << "  x2=" << x2 << "  x3=" << x3 << "\n";
	//if (x4 != x2) {
	//	if (cal(equation, x4, 0) < cal(equation, x2, 0)) {    // x4點的函式值如圖中f4b所示時
	//		if (x3 - x2 > x2 - x1) {    // b > a，右半區間長度較大
	//			return golden_search(x2, x4, x3, equation);  // 以x2，x4，x3作為新三點，繼續搜尋
	//		}
	//		else {    // b <= a，左半區間長度較大
	//			return golden_search(x1, x4, x2, equation);  // 以x1，x4，x2作為新三點，繼續搜尋
	//		}
	//	}
	//	else {    // x4點的函式值如圖中f4a所示時
	//		if (x3 - x2 > x2 - x1) {    // b > a，右半區間長度較大
	//			return golden_search(x1, x2, x4, equation);  // 以x1，x2，x4作為新三點，繼續搜尋
	//		}
	//		else {  // b <= a，左半區間長度較大
	//			return golden_search(x4, x2, x3, equation);  // 以x4，x2，x3作為新三點，繼續搜尋
	//		}
	//	}
	//}
	//

	int i, n;
	double d, x1, x2;
	for (i = 1; i <= 100; i++) {
		d = 0.61803*(range_max - range_min);
		x1 = range_min + d;
		x2 = range_max - d;
		if (fabs(cal(equation, x2, 0) - cal(equation, x1, 0)) < 1e-8) {
#ifdef DEBUG
			cout << "gol=" << x2 << "\n";
#endif // DEBUG		
			return x2;
		}
		if (cal(equation,x2,0) > cal(equation,x1,0)) {    /* 取右邊 */
			range_min = x2;
			x2 = x1;
		}
		else {              /* 取左邊 */
			range_max = x1;
			x1 = x2;
		}
	}




}
double preventZero(double x) {
	if (x == 0)return 1;
	else return x;
}
void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output)
{
	Output->Text += "j = 1" + nL;
	Output->Text += "i = 1" + nL;
	Output->Text += "X1 = [" + iniX + "]" + nL;
	double alpha=Golden_Search(intervalX1,intervalX2,equation);	
	Output->Text += "X2 = [" + alpha + "]" + nL;
	Output->Text += nL;
	Output->Text += "[x] = [" + alpha + "]" + nL;
	Output->Text += "min = " + cal(equation,alpha,0)+nL;
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
			Output->Text += "j=" + j+ nL;
			Output->Text += "i=" + i + nL;
			if (i == 3) {
				Vector Sbuffer = a[0] * s[0] + a[1] * s[1];
				s.push_back(Sbuffer);
			}
			string bufferX = "(" + std::to_string(Xi[i-1].Data[0]) + "+x*" + std::to_string(s[i-1].Data[0]) + ")";
			string bufferY = "(" + std::to_string(Xi[i-1].Data[1]) + "+x*" + std::to_string(s[i-1].Data[1]) + ")";
			string bufferStr = variableChange(equation, bufferX, bufferY);
			double leftx, lefty, rightx,righty, left,right;
			leftx = (intervalX1 - Xi[i - 1].Data[0]) / preventZero(s[i - 1].Data[0]);
			lefty = (intervalY1 - Xi[i - 1].Data[1]) / preventZero(s[i - 1].Data[1]);
			rightx = (intervalX2 - Xi[i - 1].Data[0]) / preventZero(s[i - 1].Data[0]);
			righty = (intervalY2 - Xi[i - 1].Data[1]) / preventZero(s[i - 1].Data[1]);
			left = leftx > lefty ? leftx : lefty;
			right = rightx > righty ? righty : rightx;
			double abuff = Golden_Search(left, right, bufferStr);
			a.push_back(abuff);
			cout << "  Left = " << left << "  Right = " << right << " a= " << abuff << "\n";
			Vector x = Xi[i - 1];
			x = x+ a[i - 1] * s[i-1];
			double resultValue = cal(equation, x.Data[0], x.Data[1]);
			//cout << "  Left = " << left << "  Right = " << right <<" a= "<<abuff<< "\n";
			cout << "  i= " << i << "  j= " << j << " Vec = " << x.Data[0] << " , " << x.Data[1] << " V = " << resultValue << "\n";
			Output->Text += "X" + i + "[ " + x.Data[0] + "  " + x.Data[1]+" ]"+nL;
			Output->Text += "Alpha = " + a[i] + nL;
			if (fabs(resultValue - prevalue )<lim || (x*x).Data[0] < lim     ) {
				//cout << x.Data[0] << "   " << x.Data[1];
				Output->Text += "[ X , Y ] is " + " [ " + x.Data[0] + "  " + x.Data[1] + " ]"  + nL;
				Output->Text += "min = " + resultValue + nL;
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

void Steep_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output)
{
	vector<Vector> Xi(1);
	Xi[0].Data.push_back(iniX);
	Vector gradient;
	gradient.Data.push_back(0);
	int i = 1;
	double lamba;
	while (1) {
		// 存好gradient
		gradient.Data[0] = -1 * part_dx(equation, Xi[i - 1].Data[0],0);
		// -gradient
		string bufferX = "(" + std::to_string(Xi[i - 1].Data[0]) + "+x*" + std::to_string(gradient.Data[0]) + ")";
		string bufferStr = variableChange(equation, bufferX, "y");
		double leftx, rightx;
		leftx = (intervalX1 - Xi[i - 1].Data[0]) / preventZero(gradient.Data[0]);		
		rightx = (intervalX2 - Xi[i - 1].Data[0]) / preventZero(gradient.Data[0]);
		if (leftx > rightx)swap(leftx, rightx);
		lamba = Golden_Search(leftx, rightx, bufferStr);
		Vector temp;
		temp.Data.push_back(Xi[i - 1].Data[0] + gradient.Data[0] * lamba);
		Xi.push_back(temp);
#ifdef DEBUG
		cout << "hx       lamba        x\n";
		cout << gradient.Data[0] << "  " << lamba << "  " << temp.Data[0] << "\n";
#endif // DEBUG	
		if (norm(gradient) < lim || fabs(cal(equation, Xi[i].Data[0],0) - cal(equation, Xi[i - 1].Data[0],0)) < lim) {
#ifdef DEBUG
			cout << "finish________________result : " << cal(equation, Xi[i].Data[0], Xi[i].Data[1]) << "\n";
#endif // DEBUG	
			Output->Text += nL + "[x] = [ " + Xi[i].Data[0] + " ]" + nL;
			Output->Text += "min = " + cal(equation, Xi[i].Data[0], Xi[i].Data[1]) + nL;
			return;
		}
		Output->Text += "i = " + i + nL;
		Output->Text += "h = [ " + gradient.Data[0] + " ]" + nL;
		Output->Text += "lamba = " + lamba + nL;
		Output->Text += "X = [ " + temp.Data[0] + " ]" + nL;
		i++;
	}
}

void Steep_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output)
{
	vector<Vector> Xi(1);
	Xi[0].Data.push_back(iniX);
	Xi[0].Data.push_back(iniY);
	Vector gradient;
	gradient.Data.push_back(0);
	gradient.Data.push_back(0);
	int i = 1;
	double lamba;
	while (1) {
		Output->Text += "i= " + i  + nL;
		
		gradient.Data[0] = -1*part_dx(equation, Xi[i-1].Data[0]  , Xi[i - 1].Data[1]);
		gradient.Data[1] = -1* part_dy(equation, Xi[i - 1].Data[0], Xi[i - 1].Data[1]);
		Output->Text += "h = [ " + gradient.Data[0] + "  " + gradient.Data[1] + " ]" + nL;

		// -gradient
		string bufferX = "(" + std::to_string(Xi[i - 1].Data[0]) + "+x*" + std::to_string(gradient.Data[0]) + ")";
		string bufferY = "(" + std::to_string(Xi[i - 1].Data[1]) + "+x*" + std::to_string(gradient.Data[1]) + ")";
		string bufferStr = variableChange(equation, bufferX, bufferY);
		double leftx, lefty, rightx, righty, left, right;
		leftx = (intervalX1 - Xi[i - 1].Data[0]) / preventZero(gradient.Data[0]);
		lefty = (intervalY1 - Xi[i - 1].Data[1]) / preventZero(gradient.Data[1]);
		rightx = (intervalX2 - Xi[i - 1].Data[0]) / preventZero(gradient.Data[0]);
		righty = (intervalY2 - Xi[i - 1].Data[1]) / preventZero(gradient.Data[1]);
		left = leftx > lefty ? leftx : lefty;
		right = rightx > righty ? righty : rightx;
		lamba = Golden_Search(left,right,bufferStr);
		
		Vector temp;
		temp.Data.push_back(Xi[i-1].Data[0]+gradient.Data[0]*lamba);
		temp.Data.push_back(Xi[i - 1].Data[1] + gradient.Data[1]*lamba);
		Xi.push_back(temp);
		Output->Text += "X = [ " + temp.Data[0] + "  " + temp.Data[1] + " ]" + nL;
		cout << "hx        hy        lamba        x    y    \n";
		cout << gradient.Data[0] << "  " << gradient.Data[1] << "  " << lamba << "  " << temp.Data[0] << "  " << temp.Data[1] << "\n";
		if (norm(gradient) < lim || fabs(cal(equation, Xi[i].Data[0], Xi[i].Data[1]) - cal(equation, Xi[i - 1].Data[0], Xi[i - 1].Data[1])) < lim) {
			Output->Text += "[ X , Y ] is " + " [ " + Xi[i].Data[0] + "  " + Xi[i].Data[1] + " ]" + nL;
			Output->Text += "min = " + cal(equation, Xi[i].Data[0], Xi[i].Data[1]) + nL;
			cout << "finish________________result : " << cal(equation, Xi[i].Data[0], Xi[i].Data[1])<<"\n";
			return;
		}
		i++;		
	}
}

void ConjugateGradient_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output)
{
	vector<Vector> Xi;
	vector<Vector> B;
	vector<double> a;
	vector<Vector> d;
	vector<Vector> g;
	g.push_back(Makegradient(equation,iniX,iniY));
	vector<double> data;
	Vector tempVector;
	data.push_back(iniX);
	data.push_back(iniY);
	Xi.push_back(Vector(data));
	tempVector = -1 * Makegradient(equation,iniX,iniY);
	d.push_back(tempVector);
	int i = 1;
	while (1) {
		//double tempa = Golden_Search(,);
		string bufferX = "(" + std::to_string(Xi[i - 1].Data[0]) + "+x*" + std::to_string(d[i-1].Data[0]) + ")";
		string bufferY = "(" + std::to_string(Xi[i - 1].Data[1]) + "+x*" + std::to_string(d[i - 1].Data[1]) + ")";
		string bufferStr = variableChange(equation, bufferX, bufferY);
		double leftx, lefty, rightx, righty, left, right;
		leftx = (intervalX1 - Xi[i - 1].Data[0]) / preventZero(d[i - 1].Data[0]);
		rightx = (intervalX2 - Xi[i - 1].Data[0]) / preventZero(d[i - 1].Data[0]);
		if (leftx > rightx)swap(leftx , rightx);
		lefty = (intervalY1 - Xi[i - 1].Data[1]) / preventZero(d[i - 1].Data[1]);
		righty = (intervalY2 - Xi[i - 1].Data[1]) / preventZero(d[i - 1].Data[1]);
		if (lefty > righty)swap(lefty, righty);
		left = leftx > lefty ? leftx : lefty;
		right = rightx > righty ? righty : rightx;
		if (left > right)swap(left,right);
		double tempa = golden_search(left,right, bufferStr);
		a.push_back(tempa);
#ifdef DEBUG
		cout << "a = " << tempa << "\n";
#endif // DEBUG
		Vector tempV;
		tempV.Data.push_back(Xi[i - 1].Data[0] + a[i-1] * d[i-1].Data[0]);
		tempV.Data.push_back(Xi[i - 1].Data[1] + a[i-1] * d[i-1].Data[1]);
		Xi.push_back(tempV);
		if (fabs(cal(equation, Xi[i].Data[0], Xi[i].Data[1]) - cal(equation, Xi[i - 1].Data[0], Xi[i - 1].Data[1])) < lim) {
			cout << "result is " << cal(equation, Xi[i].Data[0], Xi[i].Data[1]) << "\n";
			cout << " Xi = " << Xi[i].Data[0] <<"   "<<Xi[i].Data[1] ;
			return;
		}
#ifdef DEBUG
		cout << "x" << i << " = " << tempV.Data[0] << " , " << tempV.Data[1] << "\n";
#endif // DEBUG	
		g.push_back(Makegradient(equation, tempV.Data[0],tempV.Data[1]));

		double tempB = (g[i] * g[i]).Data[0] / (g[i - 1] * g[i - 1]).Data[0];
		Vector tempD = -1 * Makegradient(equation, tempV.Data[0], tempV.Data[1]) + tempB *d[i-1];
#ifdef DEBUG
		
#endif // DEBUG
		d.push_back(tempD);
		cout << "===========================================\n";
		i++;
	}







}

Vector Makegradient(string equation, double x, double y)
{
	double rx = part_dx(equation,x,y);
	double ry = part_dy(equation, x, y);
	vector<double>data;
	data.push_back(rx);
	data.push_back(ry);
	return Vector(data);
}
