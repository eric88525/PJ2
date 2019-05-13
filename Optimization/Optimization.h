#pragma once
#include<string>
#include<vector>
#define PHI  0.618033991   
#define RESPHI  0.381966011
#define tau 1e-5
using  std::string;
using namespace System::Windows::Forms;
enum Error {
	no_select_item,//�S����ܤ�{���Τ�k
	input_error,
};

std::vector<string> IntoPost(std::string str); //���������
bool isNumber(string x);
int priority(std::string op); //�u���v


//�o�ǧڰѦҾǪ��x  �n�[�\��N�b�o�w�q �bOptimization.cpp��@
// �ڥu���w�q�n �٨S��@

/* www.itread01.com/content/1541615343.html */
double cal(string equation,double x,double y); //�p��f(x,y) �]�i�Ψӳ�­p��f(x) or f(y)

double golden_search(double x1, double x2, double x3, double x4); 

void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^Output);
void powell_method(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Newton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Newton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Steep_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Steep_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void QuasiNewton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void QuasiNewton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void ConjugateGradient_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);