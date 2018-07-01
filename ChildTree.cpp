#include <cstdio>
struct BinaryTreeNode
{
	double                 m_dbValue;
	BinaryTreeNode*        m_pLeft;
	BinaryTreeNode*        m_pRight;
};
bool Equal(double a, double b){
	if (a - b > -0.0000001 && a - b < 0.0000001)
		return true;
	else
		return false;
}
bool HasSubtreeCore(BinaryTreeNode *treea, BinaryTreeNode *treeb){
	if (treeb == NULL){
		return true;
	}
	if (treea == NULL){
		return false;
	}
	if (!Equal(treea->m_dbValue,treeb->m_dbValue)){
		return false;
	}
	return HasSubtreeCore(treea->m_pLeft, treeb->m_pLeft) && HasSubtreeCore(treea->m_pRight, treeb->m_pRight);
}
bool HasSubtree(BinaryTreeNode *treea, BinaryTreeNode *treeb){
	bool result = false;
	if (treeb == NULL){
		result = true;
	}
	if (treea == NULL){
		result = false;
	}
	if (treea != NULL && treeb != NULL){
		if (Equal(treea->m_dbValue,treeb->m_dbValue)){
			result = HasSubtreeCore(treea, treeb);
		}
		if (!result){
			result = HasSubtree(treea->m_pLeft, treeb);
		}
		if (!result){
			result = HasSubtree(treea->m_pRight, treeb);
		}
	}
	return result;
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

void Test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
	if (HasSubtree(pRoot1, pRoot2) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s failed.\n", testName);
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

	BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
	//BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

	//ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);
	ConnectTreeNodes(pNodeB1, pNodeB2, NULL);

	Test("Test1", pNodeA1, pNodeB1, true);

	DestroyTree(pNodeA1);
	DestroyTree(pNodeB1);
}
int main(int argc, char* argv[])
{
	Test1();
	return 0;
}
