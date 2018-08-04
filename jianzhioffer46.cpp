#include <cstdio>
int main(){
	int a = 122;
	int num[1000];
	int k = 0;
	int count[1000];
	int i = 0;
	while (a != 0){
		num[k] = a % 10;
		k++;
		a = a / 10;
	}
	count[0] = 1;
	if (num[1] * 10 + num[0] >= 10 && num[1] * 10 + num[0] <= 25){
		count[1] = 2;
	}
	else
		count[1] = 1;
	for (i = 2; i < k; i++){
		if (num[i] * 10 + num[i - 1] >= 10 && num[i] * 10 + num[i - 1] <= 25){
			count[i] = count[i - 1] + count[i - 2];
		}
		else
			count[i] = count[i - 1];
	}
	printf("%d", count[i - 1]);
	return 0;
}