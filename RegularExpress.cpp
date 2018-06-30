#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
bool MatchCore(char *p1, char *p2){
	if (*p1 == '\0' && *p2 == '\0'){
		return true;
	}
	if (*p2 == '\0' && *p1 != '\0'){
		return false;
	}
	if (*(p2 + 1) == '*'){
		if (*p1 == *p2 || (*p2 == '.' && *p1 != '\0')){
			return MatchCore(p1 + 1, p2) || MatchCore(p1 + 1, p2 + 2) || MatchCore(p1, p2 + 2);
		}
		else{
			return MatchCore(p1, p2 + 2);
		}
	}
	if (*p1 == *p2 || (*p1!='\0' && *p2=='.'))
		return MatchCore(p1 + 1, p2 + 1);
	return false;
}
bool Match(char *p1, char *p2){
	if (p1 == NULL || p2 == NULL){
		return false;
	}
	return MatchCore(p1, p2);
}
int main(int argc, char* argv[]){
	char str1[] = { "aaa"};
	char pattern[] = {"ab*ac*a"};
	bool match = false;
	match = Match(str1, pattern);
	cout << match << endl;
	return 0;
}