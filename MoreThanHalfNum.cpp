#include <iostream>
#include <cstdio>
void swap(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}
int partition(int *number, int start, int end){
	int i = start;
	int j = end + 1;
	while (true){
		while (number[++i] <= number[start]){
			if (i == end)
				break;
		}
		while (number[--j] >= number[start]){
			if (j == start)
				break;
		}
		if (i > j)
			break;
		swap(number[i], number[j]);
	}
	swap(number[start], number[j]);
	return j;
}
bool IsMoreThanHalf(int *number, int length, int predict){
	int count = 0;
	for (int i = 0; i < length; i++){
		if (number[i] == number[predict]){
			count++;
		}
	}
	if (count * 2 < length){
		return false;
	}
	else
		return true;
}
int Test1(int *number, int length){
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = 0;
	int predict = 0;
	while (index != middle){
		index = partition(number, start, end);
		if (index > middle){
			end = index - 1;
			index = partition(number, start, index - 1);
		}
		else{
			start = index + 1;
			index = partition(number, index + 1, end);
		}
	}
	predict = number[index];
	if (!IsMoreThanHalf(number, length, index))
		predict = 0;
	return predict;
}
void Test(int *number, int length, int result){
	if (number == NULL || length <= 0){
		return;
	}
	printf("test is going.");
	int predict = Test1(number, length);
	printf("predict is %d", predict);
	//if (predict == )
}
int main(){
	int number[] = { 1, 2, 3, 3, 3, 3, 5, 4, 3 };
	int result = 3;
	int length = sizeof(number) / sizeof(int);
	Test(number, length, result);
	for (int i = 0; i < length; i++){
		printf("%d", number[i]);
	}
	return 0;
}