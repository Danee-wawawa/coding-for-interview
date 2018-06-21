#include <cstdio>

using namespace std;

bool duplicational(int number[], int numberLength, int *duplicate){
	if(number == NULL || numberLength <= 0){
		return false;
	
	}
	for(int i=0;i<numberLength;i++){
		if(number[i] < 0 || number[i] > numberLength-1)
			return false;
	
	}
	for(int i=0;i<numberLength;i++){
		while(number[i] != i){
			if(number[i] == number[number[i]]){
				*duplicate = number[i];
			    return true;
			}
		    else{
				int temp = 0;
				temp = number[i];
				number[i] = number[temp];
				number[temp] = temp;
			}
		}       
	}
	return false;

}

bool contains(int duplication[], int dupLength, int number){
	for(int i=0;i<dupLength;i++){
		if(duplication[i] == number)
			return true;
	}
	return false;
}

void test(char *testName,int number[],int numberLength,int duplication[],int dupLength, bool validAug){
	printf("%s is testing", testName);
	int duplicate;
	bool state = duplicational(number, numberLength, &duplicate);
	if(validAug == state){
		if(validAug){
			if(contains(duplication,dupLength,duplicate))
				printf("PASS");
			else
				printf("FAILED");
		}
	}
	else
		printf("FAILED");

}
void test1(){
	int number[] = {2,4,2,1,4};
	int duplication[] = {2,4};
	test("test1",number,sizeof(number)/sizeof(int),duplication,sizeof(duplication)/sizeof(int),true);

}
int main(){
	test1();
	return 0;
}
