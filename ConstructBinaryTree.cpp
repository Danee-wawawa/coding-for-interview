#include <iostream>
#include <cstdio>
using namespace std;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_left;
	BinaryTreeNode* m_right;
};
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);
BinaryTreeNode* ConstructTree(int *preorder, int *inorder, int length);
BinaryTreeNode* ConstructCore(int *startpreorder, int *endpreorder, int *startinorder, int *endinorder){
	int rootValue = startpreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_left = NULL;
	root->m_right = NULL;
	if (startpreorder == endpreorder){
		//cout << startpreorder << endl;
		//cout << endpreorder << endl;
		if (startinorder == endinorder && *startinorder == *startpreorder){
			return root;
		}
		else{
			printf("invalid input.");
			return NULL;
		}
	}
	int* rootinorder = startinorder;
	while (rootinorder <= endinorder && *rootinorder != rootValue){
		rootinorder++;
	}
	if (rootinorder == endinorder && *rootinorder != rootValue){
		printf("invalid input.");
		return NULL;
	}
	int leftlength = rootinorder - startinorder;
	int* leftPreorderEnd = startpreorder + leftlength;
	if (leftlength > 0){
		root->m_left = ConstructCore(startpreorder + 1, startpreorder + leftlength, startinorder, startinorder + leftlength - 1);
	}
	if (leftlength < endpreorder - startpreorder){
		root->m_right = ConstructCore(leftPreorderEnd + 1, endpreorder, rootinorder + 1, endinorder);
	}
	return root;
}
BinaryTreeNode* ConstructTree(int *preorder, int *inorder, int length){
	if (preorder == NULL || inorder == NULL || length <= 0){
		return NULL;
	}

		//cout << preorder << endl;
		//cout << preorder+length-1 << endl;
		//cout << preorder[0] << endl;
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);

}
void printNode(BinaryTreeNode* node){
	if (node != NULL){
		printf("root is %d", node->m_nValue);
		if (node->m_left != NULL){
			printf("leftroot is %d\n", node->m_left->m_nValue);
		}
		else{
			printf("left is null\n");
		}
		if (node->m_right != NULL){
			printf("rightroot is %d\n", node->m_right->m_nValue);
		}
		else{
			printf("right is null\n");
		}
	}
	else{
		printf("root is null\n");
	}

}
void printTree(BinaryTreeNode* root){
	printNode(root);
	if (root != NULL){
		if (root->m_left != NULL){
			printTree(root->m_left);
		}
		if (root->m_right != NULL){
			printTree(root->m_right);
		}
	}
}
void test1(){
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int length = 8;
		//int *preorder = pre;
		//int *inorder = in;
	BinaryTreeNode* root = ConstructTree(pre, in, length);
	printTree(root);
}
int main(int argc, char* argv[]){
	test1();
	return 0;
}