#include <iostream>
#include <stdexcept>
#include <cstdio>
using namespace std;
int movingCout(int threshold, int rows, int cols);
int movingCoutCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool *visited);
int getSum(int num);
int movingCout(int threshold, int rows, int cols){
    if(threshold < 0 || rows <= 0 || cols <= 0){
        return 0;
    }
    bool *visited = new bool[rows*cols];
    for(int i=0;i<rows*cols;i++){
        visited[i] = false;
    }
    int count = movingCoutCore(threshold, rows, cols, 0,0,visited);
    delete[] visited;
    return count;
}
int movingCoutCore(int threshold, int rows, int cols, int row, int col, bool* visited){
    int count = 0;
    if(check(threshold, rows, cols, row, col, visited)){
        visited[row*cols + col] = true;
        count = 1 +  movingCoutCore(threshold, rows, cols, row, col - 1,visited) 
                + movingCoutCore(threshold, rows, cols, row, col + 1,visited) 
                + movingCoutCore(threshold, rows, cols, row - 1, col,visited) 
                + movingCoutCore(threshold, rows, cols, row + 1, col,visited);
    }
    return count;
}
bool check(int threshold, int rows, int cols, int row, int col, bool *visited){
    if(!visited[row * cols + col] && getSum(row) + getSum(col) <= threshold && row>=0 && col >=0 && row<=rows && col<=cols){
        return true;
    }
    return false;
}
int getSum(int num){
    int sum  = 0;
    while(num > 0){
        sum = sum + num%10;
        num = num/10;
    }
    return sum;
}
int main() {
    int rows = 4;
    int cols = 3;
    int threshold = 1;
    int result = movingCout(threshold, rows, cols);
    printf("%d",result);
	return 0;
}