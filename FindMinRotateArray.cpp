#include <iostream>
#include <stdexcept>
#include <cstdio>
using namespace std;
int MinInOrder(int a[], int length){
    int min = 0;
    for(int i = 1;i < length;i++){
        if(a[min] > a[i]){
            min = i;
        }
    }
    return a[min];
}
int Min(int a[], int length){
    if(a == NULL || length <= 0){
        std::logic_error ex("Invalid input");
        throw new std::exception(ex);
    }
    int p1 = 0;
    int p2 = length - 1;
    int mid = p1;
    while(a[p1] >= a[p2]){
        if(p2 - p1 == 1){
            mid = p2;
            break;
        }
        mid = (p1 + p2)/2;
        if(a[mid] == a[p1] && a[mid] == a[p2]){
            return MinInOrder(a,length);
        }
        if(a[mid] >= a[p1]){
            p1 = mid;
        }
        else if(a[mid] <= a[p2]){
            p2 = mid;
        }
    }
    return a[mid];
    
}
int main() {
    int a[] = {1,0,1,1,1,1};
    int length = sizeof(a)/sizeof(int);
    int result = Min(a,length);
    printf("%d",result);
	return 0;
}