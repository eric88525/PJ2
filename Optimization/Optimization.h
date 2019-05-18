#pragma once
#include<string>
#include<vector>
#include<math.h>
#include"Vector.h"
#include"Matrix.h"
#include "Error.h"
#define PHI  0.618033991   
#define RESPHI  0.381966011
#define nL System::Environment::NewLine
#define tau 1e-5
#define H 3e-5
#define lim 1.0e-8
#define PI 3.14159265
using  std::string;
using namespace System::Windows::Forms;


std::vector<string> IntoPost(std::string str); //中續轉後續
bool isNumber(string x);
int priority(std::string op); //優先權

//這些我參考學長ㄉ  要加功能就在這定義 在Optimization.cpp實作
// 我只有定義好 還沒實作

/* www.itread01.com/content/1541615343.html */
string variableChange(string &ori,string x,string y); //變數字串代換

double cal(string equation,double x,double y); //計算f(x,y) 也可用來單純計算f(x) or f(y)

double part_dx(string equation, double x, double y);//X一次偏微
double part_dxx(string equation, double x, double y);//X二次偏微
double part_dy(string equation, double x, double y);//Y一次偏微
double part_dyy(string equation, double x, double y);//Y二次偏微

double Golden_Search(double range_min, double range_max, string equation);
double golden_search(double range_min, double range_max,std::string equation);

void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^Output);
void powell_method(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Newton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Newton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Steep_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Steep_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void QuasiNewton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void QuasiNewton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void ConjugateGradient_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);