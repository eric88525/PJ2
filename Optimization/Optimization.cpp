#include "Optimization.h"

int priority(char op) {
	switch (op) {
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '_': case '^': return 3; // �t�� ����
	case '$': return 4;			//�T�����
	default:            return 0;
	}
}

std::string IntoPost(std::string str) {

	for (int i = 0; i < str.length();i++) {
		if (str[i] == '-') {
			if (i == 0) str[i] = '_';
			else{
				std::string cmp = "(+-*/^";
				for (auto j:cmp) {
					if (str[i - 1] == j)str[i] = '_';
					break;
				}
			}
		}
	}
	std::string stack = "";
	std::string postfix = "";
	for (int i = 0; i < str.length(); i++) {
		switch (str[i]) {
		case '(':     // �B��l���| 	
			stack.push_back(str[i]);
			break;
		case '+': case '-': case '*':case '/': case '^':case '_':

			while (stack.length() && priority(stack[stack.length() - 1]) >= priority(str[i])) {
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			stack.push_back(str[i]); // �s�J���| 
			break;
		case ')':
			while (stack[stack.length() - 1] != '(') { // �J ) ��X�� ( 
				postfix.push_back(stack[stack.length() - 1]);
				stack.pop_back();
			}
			if (stack[stack.length() - 1] == '(') stack.pop_back();
			break;
		case 'x':  // �B�⤸������X 
			
			postfix.push_back('x');
			break;
		case 'y':  // �B�⤸������X 

			postfix.push_back('y');
			break;
		default:  // �B�⤸������X
			postfix.push_back(str[i]);
			break;
		}
	}
	for (int i = stack.length() - 1; i >= 0;i--) {
		postfix += stack[i];
	}
	
	for (int l = 0; l < postfix.length(); l++) {
		if (postfix[l] == '(' || postfix[l] == ')')postfix.erase(l, 1);
	}
	return postfix;
}