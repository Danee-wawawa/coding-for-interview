#include<iostream>
#include<cstdlib>
using namespace std;
void Merge(int a[], int p1[], int start, int center, int end){
	int i = start;
	int j = center + 1;
	for (int k = start; k <= end; k++){
		if (i > center){
			p1[k] = a[j++];
		}
		else if (j > end){
			p1[k] = a[i++];
		}
		else if (a[i] <= a[j]){
			p1[k] = a[i];
			i++;
		}
		else if (a[j] < a[i]){
			p1[k] = a[j];
			j++;
		}

	}
	for (int k = start; k <= end; k++)
		a[k] = p1[k];
}
void MergeSort(int a[], int p1[], int start, int end){
	if (start < end){
		int center = (start + end) / 2;
		MergeSort(a, p1, start, center);
		MergeSort(a, p1, center + 1, end);
		Merge(a, p1, start, center, end);
	}
}
int main(){
	int a[] = { 3, 7, 5, 4, 1, 6, 2 };
	int length = sizeof(a) / sizeof(int);
	int start = 0;
	int end = length - 1;
	int *p1;
	p1 = (int *)malloc((end - start + 1)*sizeof(int));
	MergeSort(a, p1, start, end);
	for (int i = 0; i < length; i++){
		cout << a[i] << endl;
	}
	return 0;
}