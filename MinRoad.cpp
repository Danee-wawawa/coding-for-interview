#include <cstdio>
#define N 100
int dis[N][N];
int Tree[N];
int mod(int a, int i){
	int emp = 1;
	while (i--){
		emp = (emp * a) % 100000;
	}
	return emp;
}
int FindRoot(int a){
	if (Tree[a] == -1){
		return a;
	}
	else{
		Tree[a] = FindRoot(Tree[a]);
		return Tree[a];
	}
}
int main(){
	int n, m;
	scanf_s("%d%d", &n, &m);
	int i, j, a, b, x, y, dist, k, l;
	for (i = 0; i < n; i++){
		Tree[i] = -1;
		for (j = 0; j < n; j++){
			dis[i][j] = -1;
		}
		dis[i][i] = 0;
	}
	for (i = 0; i < m; i++){
		scanf_s("%d%d", &a, &b);
		x = FindRoot(a);
		y = FindRoot(b);
		if (x != y){
			dist = mod(2, i);
			for (k = 0; k < n; k++){
				if (x == FindRoot(k)){
					for (l = 0; l < n; l++){
						if (y == FindRoot(l)){
							dis[k][l] = dis[l][k] = (dis[k][a] + dis[b][l] + dist) % 100000;
						}
					}
				}

			}
			Tree[y] = x;
		}
	}
	x = FindRoot(0);
	for (i = 1; i < n; i++){
		printf("%d", dis[0][i]);
	}
	return 0;
}
