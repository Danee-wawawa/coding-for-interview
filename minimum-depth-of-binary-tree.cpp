/**
* 方法1 递归
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL){
			return minDepth(root->right) + 1;
		}
		if (root->right == NULL){
			return minDepth(root->left) + 1;
		}
		int leftdepth = minDepth(root->left);
		int rightdepth = minDepth(root->right);
		return (leftdepth>rightdepth) ? (rightdepth + 1) : (leftdepth + 1);
	}
};
/**
* 方法2 队列  时间消耗更少
*/
class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		int result = 1;
		int count = 0;
		while (!q.empty()){
			count = q.size();
			while (count>0){
				TreeNode* tmp = q.front();
				if (tmp->left == NULL && tmp->right == NULL)
					return result;
				q.pop();
				if (tmp->left != NULL)
					q.push(tmp->left);
				if (tmp->right != NULL)
					q.push(tmp->right);
				count--;
			}
			result++;
		}
	}
};