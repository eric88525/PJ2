#pragma once
#include<string>
using  std::string;
using namespace System::Windows::Forms;

typedef struct Variable { // �ܼ� :y^2 �Ѧ����q
	char name;
	double exp;
	Variable *next;
}Variable;

typedef struct Term { //�㶵 : -3.25y^2 �Ѧ����q
	double coef;
	Variable *vars;
	Term *next;
};

std::string IntoPost(std::string str); //���������
int priority(char op); //�u���v


//�o�ǧڰѦҾǪ��x  �n�[�\��N�b�o�w�q �bOptimization.cpp��@
// �ڥu���w�q�n �٨S��@
void powell_method_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^Output);
void powell_method(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Newton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Newton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void Steep_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void Steep_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void QuasiNewton_1dim(string equation, double iniX, double intervalX1, double intervalX2, TextBox ^ Output);
void QuasiNewton_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);

void ConjugateGradient_2dim(string equation, double iniX, double iniY, double intervalX1, double intervalX2, double intervalY1, double intervalY2, TextBox ^ Output);