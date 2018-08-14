#include <iostream>
using namespace std;
int ResultMiddle(char *s1, char *s2){
	int i = 0, j = 0;
	int k = 0;
	char s[200];
	int middle;
	int len1 = strlen(s1);
	//cout << len1;
	int len2 = strlen(s2);
	//cout << len2;
	while (i < len1 && j < len2){
		if (s1[i] <= s2[j]){
			s[k] = s1[i];
			i++;
			k++;
		}
		else{
			s[k] = s2[j];
			j++;
			k++;
		}
	}
	while (i < len1){
		s[k] = s1[i];
		i++;
		k++;
	}
	while (j < len2){
		s[k] = s2[j];
		j++;
		k++;
	}
	if (k % 2 == 0){
		middle = (s[k / 2] + s[k / 2 - 1]) / 2;
	}
	else
		middle = s[k / 2] / 2;
	return middle;
}
int main(){
	char nums1[100] = { 2, 5, 6, 8 };
	char nums2[100] = { 4, 7 };
	int middle = ResultMiddle(nums1, nums2);
	printf("%d", middle);
	return 0;
}