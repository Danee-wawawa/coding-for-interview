#include <cstdio>
#include <string.h>
int main(){
	char str1[1000];
	int num[1000];
	gets_s(str1);
	int i = 0;
	int j = 0;
	int k = 0;
	bool flag = false;
	int length = strlen(str1);
	for (i = 0; i < length; i++){
		flag = false;
		j = i + 1;
		while (str1[j] != '\0'){
			for (int m = i; m < j; m++){
				if (str1[m] == str1[j])
					flag = true;
			}
			if (flag == true)
				break;
			j++;
		}
		//for (k = i; k < j; k++){
		//	if (str1[j] != '\0' && str1[j] != str1[k]){
		//		j++;
		//	}
		//}
		num[k] = j - i;
		if (num[k] == length - i)
			break;
		k++;
	}
	int max = num[0];
	int index = 0;
	for (i = 0; i <= k; i++){
		flag = false;
		if (num[i] >= max){
			max = num[i];
			flag = true;
		}
		if (flag == true)
			index = i;
	}
	printf("%d\n", max);
	for (i = index; i < index + num[index]; i++)
		printf("%c\n", str1[i]);
	return 0;
}