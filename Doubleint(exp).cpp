#include<cstdio>
#include<cstdlib>
#include<math.h>
double Power(double base, int exponent) {
	if (exponent == 0)
		return 1.0;

	if (fabs(base) < 1e-5)
		return 0.0;

	if (fabs(base - 1) < 1e-5)
		return 1;

	if (fabs(base + 1) < 1e-5)
		return exponent % 2 ? -1 : 1;

	if (exponent < 0){
		base = 1.0 / base;
		exponent = -exponent;
	}

	double res = 1.0;
	while (exponent){
		if (exponent % 2){
			res *= base;
		}

		base *= base;
		exponent >>= 1;
	}
	return res;
}
int main(){
	int n;
	scanf_s("%d", &n);
	double m;
	scanf_s("%lf", &m);
	double res = Power(m, n);
	printf("%lf", res);
	system("pause");
	return 0;
}
