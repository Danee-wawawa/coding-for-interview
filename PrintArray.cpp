#include<cstdio>
void PrintCircleCore(int number[][4], int rows, int cols, int start){
	int endx = cols - start - 1;
	int endy = rows - start - 1;
	for (int i = start; i <= endx; i++){
		printf("%d", number[start][i]);
	}
	if (start < endy){
		for (int i = start + 1; i <= endy;i++)
			printf("%d", number[i][endx]);
	}
	if (start < endx && start < endy){
		for (int i = endx-1; i >=start; i--)
			printf("%d", number[endy][i]);
	}
	if (start < endy - 1 && start < endx){
		for (int i = endy - 1; i>start; i--)
			printf("%d", number[i][start]);
	}
}
void PrintCircle(int number[][4], int rows, int cols){
	if (number == NULL || rows<=0 || cols<=0){
		return;
	}
	int start = 0;
	while (rows > start * 2 && cols > start * 2){
		PrintCircleCore(number, rows, cols, start);
		start++;
	}
}
int main(){
	int number[][4] = { 1, 2, 3, 4, 5, 6 ,7,8,9,10,11,12,13,14,15,16};
	int cols = 4;
	int rows = 4;
	PrintCircle(number, rows, cols);
	return 0;
}