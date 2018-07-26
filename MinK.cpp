#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;
int main(){
	int a[1000];
	int i = 0;
	int k = 0;
	int temp = 0;
	bool flag = false;
	do{
		scanf_s("%d", &a[i++]);
	} while (getchar() != '\n');
	//printf("%d", a[1]);
	int length = i;
	scanf_s("%d", &k);
	for (int j = k; j < length; j++){
		flag = false;
		for (i = 0; i < k; i++){
			if (a[j] < a[i]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				flag = true;
				break;
			}
		}
		if (flag == true){
			j = j - 1;
		}
	}
	for (i = 0; i < k; i++){
		printf("%d", a[i]);
	}
	return 0;
}
