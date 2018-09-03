#include<cstdio>
#include<cstdlib>
#include<malloc.h>
#include<string.h>
int main(){
	//输入二维数组 N*N
	int N;
	scanf_s("%d", &N);
	int **a;
	int *b;
	a = (int **)malloc(N*sizeof(int*));
	b = (int *)malloc(N*sizeof(int));
	memset(b, 0, sizeof(b)*N);
	for (int i = 0; i < N; i++){
		printf("%d", b[i]);
	}
	for (int i = 0; i < N; i++){
		a[i] = (int *)malloc(N*sizeof(int));
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;

}
