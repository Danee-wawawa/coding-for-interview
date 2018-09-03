#include <cstdio>
#include <string.h>
#include <cstdlib>
void FindLength(char* str1, int len){
	int i = 0, j = 0, k = 0, count = 0, result = 0;
	bool flag = true;
	for (i = 1; i <= len / 2; i++){
		if (len%i != 0){
			continue;
		}
		count = len / i;
		flag = true;
		for (j = 0; j < i; j++){
			k = 0;
			while (k < (count - 1)*i){
				if (str1[k] == str1[k + i]){
					k = k + i;
				}
				else{
					flag = false;
					break;
				}
			}
			if (flag == false){
				break;
			}
		}
		if (j >= i){
			result = i;
		}

	}
	if (result == 0){
		printf("false");
		return;
	}
	for (j = 0; j < result; j++){
		printf("%c", str1[j]);
	}
	//return result;
}
int main(){
	char str1[100];
	scanf("%s", str1);
	int len = strlen(str1);
	//int result = FindLength(str1, len);
	FindLength(str1, len);
	//if (result > 0){
	//	printf("%d", result);
	//}
	//else{
	//	system("pause");
	//	return false;
	//}
	system("pause");
	return 0;
}