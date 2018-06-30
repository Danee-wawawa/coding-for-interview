#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};
ListNode* CreatNode(int nValue){
	ListNode* pNode = new ListNode();
	pNode->m_nValue = nValue;
	pNode->m_pNext = NULL;
	return pNode;
}
void ConnectNode(ListNode* node1, ListNode* node2){
	if (node1 == NULL){
		printf("error");
		exit(1);
	}
	node1->m_pNext = node2;
}
void printList(ListNode* node){
	printf("print start\n");
	if (node == NULL){
		return;
	}
	//ListNode* pTestNode = new ListNode();
	//pTestNode->m_nValue = 1;
	//pTestNode->m_pNext = NULL;
	while (node != NULL){
		printf("%d\t", node->m_nValue);
		node = node->m_pNext;
	}
	printf("\n");
}
void printList_iteratively(ListNode* pHead){
	printf("iteratively reverse the list\n");
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	//cout << nodes.size() << endl;
	while (!nodes.empty()){
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
	printf("\n");
}
void printList_recursively(ListNode* pHead){
	printf("recursively reverse the list\n");
	if (pHead != NULL){
		if (pHead->m_pNext != NULL){
			printList_recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}
void Destroy(ListNode* node){
	ListNode* pNode = node;
	while (node != NULL){
		node = node->m_pNext;
		delete pNode;
		pNode = node;
	}
}
void Test(ListNode** head){
	if (!head || !(*head)){
		return;
	}
	printList(*head);
	
	ListNode* pPreNode = NULL;
	ListNode* pNode = *head;
	while (pNode!= NULL){
		bool needDelete = false;
		ListNode* pNext = pNode->m_pNext;
		if (pNext!=NULL && pNext->m_nValue == pNode->m_nValue){
			needDelete = true;
		}
		if (!needDelete){
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else{
			int value = pNode->m_nValue;
			ListNode* pDelete = pNode;
			while (pDelete != NULL && pDelete->m_nValue == value){
				pNext = pDelete->m_pNext;
				delete pDelete;
				pDelete = NULL;
				pDelete = pNext;
			}
			if (pPreNode == NULL){
				*head = pNext;
			}
			else{
				pPreNode->m_pNext = pNext;
			}
			pNode = pNext;
		}
	}
	printList(*head);
	//Destroy(*head);
	//printList_iteratively(node);
	//printList_recursively(node);
}
void Test1(){
	printf("test1 is running\n");
	ListNode* node1 = CreatNode(1);
	ListNode* node2 = CreatNode(2);
	ListNode* node3 = CreatNode(3);
	ListNode* node4 = CreatNode(3);
	ListNode* node5 = CreatNode(4);
	ListNode* node6 = CreatNode(4);
	ListNode* node7 = CreatNode(4);
	ConnectNode(node1, node2);
	ConnectNode(node2, node3);
	ConnectNode(node3, node4);
	ConnectNode(node4, node5);
	ConnectNode(node5, node6);
	ConnectNode(node6, node7);
	Test(&node1);
	Destroy(node1);
}
int main(int argc, char* argv[]){
	Test1();
	int n;
	cin >> n;
	return 0;
}