#include<iostream>
#include<cstdio>
bool VerifyBST(int *sequence, int length){
	int root = sequence[length - 1];
	int i = 0;
	int j = 0;
	bool left = true;
	bool right = true;
	for (i = 0; i < length-1; i++){
		if (sequence[i] > root)
			break;
	}
	for (j = i; j < length; j++){
		if (sequence[j] < root)
			return false;
	}
	if (i>0)
		left = VerifyBST(sequence, i - 1);
	if (i < length - 1)
		right = VerifyBST(sequence+i, length - i - 1);
	return (left && right);

}
void Test(char *str1, int *sequence, int length, bool expected){
	printf("%s is going", str1);
	if (sequence == NULL || length == NULL){
		return;
	}
	bool result = VerifyBST(sequence, length);
	if (result == expected)
		printf("pass");
	else
		printf("fail");
}
int main(){
	int sequence[] = {7,4,6,5};
	int length = sizeof(sequence) / sizeof(int);
	bool expected = false;
	Test("test1", sequence, length,expected);
	return 0;
}