#include <iostream>
using namespace std;
#include <cstdio>
bool Find(int *matrix, int row, int col, int number){
    bool find = false;
    int rows = row - 1;
    int cols = 0;
    if(matrix != NULL && row>0 && col>0){
        while(rows >= 0 && cols <= col-1){
            if(number > matrix[rows*col + cols]){
                cols += 1;
            }
            else if(number < matrix[rows*col + cols]){
                rows -= 1;
            }
            else{
                find = true;
                break;
            }
        }
    }
    return find;
}
void Test(char *testname, int *matrix, int row, int col, int number, bool expected){
    if(testname != NULL)
        cout << testname << "is testing: " << endl;
        printf("%s is testing: ", testname);
    bool cout = Find(matrix, row, col, number);
    if(cout == expected){
        printf("passes");
    }
    else{
        printf("failed");
    }
}

void Test1(){
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 3, false);
}
int main(){
	Test1();
	return 0;
}