#include<cstdio>
#include<cstdlib>
#include<math.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int maxArea(int* height, int heightSize) {
	int res = 0;
	int l = 0;
	int r = heightSize - 1;
	while (l < r){
		res = max(res, min(height[l], height[r])*(r - l));
		if (height[l] < height[r])
			l++;
		else
			r--;
	}
	return res;

}
int main(){
	int hs;
	scanf_s("%d", &hs);
	int num[100];
	for (int i = 0; i < hs; i++){
		scanf_s("%d", &num[i]);
	}
	int res = maxArea(num, hs);
	printf("%d", res);
	system("pause");
	return 0;
}
