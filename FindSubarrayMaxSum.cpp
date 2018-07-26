#include <iostream>
#include <cstdio>
int FindMaxSum(int *a, int length){
	if (a == NULL || length <= 0)
		return 0;
	int sumva[100];
	int sum = 0;
	int i = 0;
	for (i = 0; i < length; i++){
		sumva[i] = sum < 0 ? a[i] : a[i] + sum;
		sum = sumva[i];
	}
	int max = sumva[0];
	for (i = 1; i < length; i++){
		if (max < sumva[i]){
			max = sumva[i];
		}
	}
	return max;
}
int main(){
	int a[100];
	int i = 0;
	do{
		scanf_s("%d", &a[i++]);
	} while (getchar() != '\n');
	int length = sizeof(a) / sizeof(int);
	int max = FindMaxSum(a, length);
	printf("%d", max);
	return 0;
}

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int sumva[100];
		int sum = 0;
		int i = 0;
		for (i = 0; i < array.size(); i++){
			sumva[i] = sum < 0 ? array[i] : array[i] + sum;
			sum = sumva[i];
		}
		int max = sumva[0];
		for (i = 1; i < array.size(); i++){
			if (max < sumva[i]){
				max = sumva[i];
			}
		}
		return max;
	}
};