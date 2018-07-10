#include<iostream>
using namespace std;
void Swap(int a[], int num1, int num2)
{
	int temp = a[num1];
	a[num1] = a[num2];
	a[num2] = temp;
}
int Partition(int a[], int start, int end){
	int i = start;
	int j = end + 1;
	int v = a[start];
	while (true){
		while (a[++i] < v){
			if (i == end)
				break;
		}
		while (a[--j]>v){
			if (j == start)
				break;
		}
		if (i >= j)
			break;
		Swap(a, i, j);
	}
	Swap(a, start, j);
	return j;
}
void QuickSort(int a[], int start, int end){
	if (start < end){
		int j = Partition(a, start, end);
		QuickSort(a, start, j);
		QuickSort(a, j + 1, end);
	}
}
int main(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int start = 0;
	int end = 6;
	int index = 0;
	//int index = RandomInRange(start, end);
	//std::cout << index << std::endl;
	int i = 0;
	for (i = end; i >= 0; i--){
		index = rand() % (i + 1); //generate random index 0<=index<=i
		if (i != index)
			Swap(a, i, index);
	}
	for (i = 0; i <= end; i++){
		cout << a[i] << endl;
	}
	QuickSort(a, start, end);
	for (i = 0; i <= end; i++){
		cout << a[i] << endl;
	}
	return 0;
}