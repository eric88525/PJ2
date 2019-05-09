#pragma once
#include<string>
using  std::string;
using namespace System::Windows::Forms;

typedef struct Variable { // 變數 :y^2 參考講義
	char name;
	double exp;
	Variable *next;
}Variable;

typedef struct Term { //整項 : -3.25y^2 參考講義
	double coef;
	Variable *vars;
	Term *next;
};

std::string IntoPost(std::string str); //中續轉後續
int priority(char op); //優先權


//這些我參考學長ㄉ  要加功能就在這定義 在Optimization.cpp實作
// 我只有定義好 還沒實作
void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^Output);
void powell_method(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Newton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Newton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Steep_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Steep_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void QuasiNewton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void QuasiNewton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void ConjugateGradient_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);