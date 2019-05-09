#pragma once
#include"Optimization.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>

enum Error {
	no_select_item,//�S����ܤ�{���Τ�k
};

//�w�q���޸��class
class DataManager
{
private:
	//�x�s��{�����
	std::vector<std::string> Equations;
	//�����V�qID�A�Ω󱱺�
	int EquationIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadEquationData();
	//���o�V�q���
	std::vector<std::string> GetEquations();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};