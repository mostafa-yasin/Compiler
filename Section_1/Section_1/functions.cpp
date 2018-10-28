#include <ctype.h>
#include <iostream>
#include <String>

using namespace std;


bool iskeyword(char* word) {
	char* arr[3] = {"int", "void", "bool"};

	int x;

	for(int i = 0; i < 3; i++){
		x = strcmp(word, arr[i]);
		if (x == 0){
			return true;
		}
	}
	return false;
}

bool isoperator(char op) {
	char arr[6] = {'+', '-', '*', '/', '%', '='};

	for(int i = 0; i < 6; i++) if(op == arr[i]) return true;
	
	return false;

}

bool isidentifier(char* word) {
	if (isdigit(word[0])) return false;

	if (iskeyword(word)) return false;

	for(int i = 0; i < sizeof(word); i++){
		if (word[i] == ' ') return false;
		if (isoperator(word[i])) return false;
	}

	return true;
}

void main(){

	cout << iskeyword("int") <<endl;

	cout << isoperator('+') << endl;

	cout << isidentifier("hello") << endl;

	system("pause");
}