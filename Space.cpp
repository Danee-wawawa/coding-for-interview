#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char* FindSpace(char str[], int length){
	if (str == NULL || length <= 0){
		return 0;
	}
    //char str1[50] = {};
	int i = 0;
	int spacenum = 0;
	int charnum = 0;
	while (str[i] != '\0'){
		if (str[i] == ' '){
			spacenum += 1;
		}
		charnum += 1;
		i += 1;
	}
	int total = 0;
	total = charnum + spacenum * 2;
	if (total > length){
		return 0;
	}
	int pcharnum = charnum - 1;
	int pspacenum = total - 1;
	while (pcharnum >= 0 && pspacenum > pcharnum){
		if (str[pcharnum] != ' '){
			str[pspacenum] = str[pcharnum];
			pspacenum--;
		}
		else{
			str[pspacenum] = '0';
			str[--pspacenum] = '2';
			str[--pspacenum] = '%';
			--pspacenum;
		}
		pcharnum--;
	}
	return str;

}

void Test(char *testname, char str[], int length, char expected[]){
	printf("%s is testing", testname);
	char* str1 = FindSpace(str, length);
	if (expected == NULL && str1 == NULL){
		printf("Passed");
	}
	else if (expected == NULL && str1 != NULL){
		printf("failed");
	}
	else if (strcmp(expected, str1) == 0){
		printf("passed");
	}
	else{
		printf("failed");
	}
}
void test1(){
	const int length = 100;
	char str[length] = "We are happy.";
	Test("test1", str, length, "We%20are%20happy.");
}
int main(){
	test1();
	return 0;
}