#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
bool IsPopOrder(int *seq1, int *seq2, int length){
	if (seq1 == NULL || seq2 == NULL || length == 0){
		return NULL;
	}
	stack<int> stack1;
	int j = 0;
	int i = 0;
	stack1.push(seq1[0]);
	while (seq1[i] != NULL && stack1.size() != 0){
		if (stack1.top() != seq2[j]){
			i++;
			stack1.push(seq1[i]);
		}
		else{
			stack1.pop();
			j = j + 1;
		}
	}
	if (stack1.size() == 0 && j == length){
		return true;
	}
	else
		return false;

}
void Test(char* str1, int *seq1, int *seq2, int length, bool expected){
	printf("%s is going.", str1);
	if (str1 == NULL || seq1 == NULL || seq2 == NULL){
		return;
	}
	bool result = IsPopOrder(seq1, seq2, length);
	if (expected == result){
		cout << "pass" << endl;
	}
	else
		cout << "fail" << endl;
}
int main(){
	std::stack<int> stack1, stack2;
	int seq1[] = { 1, 2, 3, 4, 5 };
	int seq2[] = { 4, 3, 5, 1, 2 };
	int length = sizeof(seq1) / sizeof(int);
	bool expected = false;
	Test("Test1", seq1, seq2, length,expected);
	return 0;
}