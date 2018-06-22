#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void MergeArray(int* A1, int& length1, int* A2, int& length2){
	int length = length1 + length2;
	int plength = length - 1;
	int plength1 = length1 - 1;
	int plength2 = length2 - 1;
	while (plength1 >= 0 && plength2 >= 0){
		if (A1[plength1] >= A2[plength2]){
			A1[plength] = A1[plength1];
			plength1--;
		}
		else{
			A1[plength] = A2[plength2];
			plength2--;
		}
//cout << A1[plength] << endl;
		plength--;
	}
	while (plength2 >= 0){
		A1[plength--] = A2[plength2--];
	}
}
int main() {
	int A1[100] = { 1, 3, 5, 7 };
	int length1 = 4;
	int A2[] = { 2, 3, 4, 5, 8 };
	int length2 = sizeof(A2) / sizeof(int);
	int A[] = { 1, 2, 3, 3, 4, 5, 5, 7, 8 };
	int length = sizeof(A) / sizeof(int);
	int i = 0;
	MergeArray(A1, length1, A2, length2);
	for (i = 0; i < length; i++){
		if (A[i] != A1[i]){
			cout << "failed" << endl;
		}
	}
	if (i >= length){
		cout << "success" << endl;
	}
	return 0;
}