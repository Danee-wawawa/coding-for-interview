#include<cstdio>
#include<iostream>
using namespace std;
bool isInteger(char **str1){
	char* before = *str1;
	while (**str1 != '\0' && **str1 >= '0' && **str1 <= '9'){
		(*str1)++;
	}
	return *str1 > before;
}
bool isSymbol(char **str1){
	if (**str1 == '-' || **str1 == '+'){
		(*str1)++;
	}
	return isInteger(str1);
}
bool isNumber(char *str1){
	if (str1 == NULL){
		return false;
	}
	bool number = isSymbol(&str1);
	if (*str1 == '.'){
		str1++;
		number =  isInteger(&str1) || number;
	}
	if (*str1 == 'e' || *str1 == 'E'){
		str1++;
		number =  isSymbol(&str1) && number;
	}
	return number && (*str1 == '\0');

}
int main(int argc, char* argv[]){
	char str1[] = { ".8e+1" };
	bool result = false;
	result = isNumber(str1);
	cout << result << endl;
	return 0;
}
