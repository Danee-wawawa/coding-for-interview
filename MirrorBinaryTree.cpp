#include <cstdio>
struct BinaryTreeNode
{
	double                 m_dbValue;
	BinaryTreeNode*        m_pLeft;
	BinaryTreeNode*        m_pRight;
};
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %.3f\n", pNode->m_dbValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %.3f\n", pNode->m_pLeft->m_dbValue);
		else
			printf("left child is nullptr.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %.3f\n", pNode->m_pRight->m_dbValue);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}

	printf("\n");
}
void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}
BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_dbValue = dbValue;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

void Test(BinaryTreeNode* pRoot1)
{
	if (pRoot1 == NULL){
		return;
	}
	if (pRoot1->m_pLeft == NULL && pRoot1->m_pRight == NULL){
		return;
	}
	BinaryTreeNode *pTemp = pRoot1->m_pLeft;
	pRoot1->m_pLeft = pRoot1->m_pRight;
	pRoot1->m_pRight = pTemp;
	if (pRoot1->m_pLeft != NULL){
		Test(pRoot1->m_pLeft);
	}
	if (pRoot1->m_pRight != NULL){
		Test(pRoot1->m_pRight);
	}
}
void Test1()
{
	BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);
	//BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	//BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	//BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);
	//ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
	//ConnectTreeNodes(pNodeB1, pNodeB2, NULL);
	PrintTree(pNodeA1);
	Test(pNodeA1);
	PrintTree(pNodeA1);
	DestroyTree(pNodeA1);
	//DestroyTree(pNodeB1);
}
int main(int argc, char* argv[])
{
	Test1();
	return 0;
}

