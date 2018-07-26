#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

int reachTarget(int target){
	target = abs(target);
	int i = 0;
	while (i*(i + 1) < 2 * target){
		i++;
	}
	if (i*(i + 1) == 2 * target){
		return i;
	}
	if ((i*(i + 1) / 2 - target) % 2 == 0){
		return i;
	}
	else if (i % 2 == 0){
		return i + 1;
	}
	else
		return i + 2;
}
int main(){
	int target;
	scanf_s("%d", &target);
	int num = reachTarget(target);
	//scanf_s(str1);
	//printf("%s\n", str1);
	printf("%d", num);
	return 0;
}
//int a[1000];
//do{
//	scanf_s("%d", &a[i++]);    //读入数据到数组当中
//} while ((getchar()) != '\n');

