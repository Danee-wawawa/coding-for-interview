#include "Queue.h"
void Test(char actual, char expected){
	if(actual == expected)
		printf("pass\n");
	else
		printf("failed\n");
}
int main(int argc, char* argv[]){
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');
	char head = queue.deleteHead();
	Test(head, 'a');
	head = queue.deleteHead();
	Test(head, 'b');
	queue.appendTail('d');
	head = queue.deleteHead();
	Test(head, 'c');
	queue.appendTail('e');
	head = deleteHead();
	Test(head, 'd');
	head = queue.deleteHead();
	Test(head, 'e');
	return 0;
}
