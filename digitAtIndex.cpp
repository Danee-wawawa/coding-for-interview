#include <iostream>
#include <cstdio>
#include <math.h>
int beginnum(int num){
	if (num == 1)
		return 0;
	return (int)std::pow(10, num - 1);
}
int FinalResult(int det, int num){
	int number = beginnum(num) + det / num;
	int fromright = num - det % num;
	for (int i = 1; i < fromright; i++)
		number = number / 10;
	return number % 10;

}
int CalCount(int num){
	if (num == 1)
		return 10;
	int count = (int)std::pow(10, num - 1);
	return 9 * count;
}
int digitIndex(int dex){
	if (dex < 0){
		return -1;
	}
	int num = 1;
	int count = 0;
	while (true){
		count = CalCount(num);
		if (dex < count*num){
			return FinalResult(dex, num);
		}
		dex = dex - count*num;
		num++;
	}
	return -1;
}
int main(){
	int dex = 0;
	scanf_s("%d", &dex);
	int result = digitIndex(dex);
	printf("%d", result);
	return 0;
}