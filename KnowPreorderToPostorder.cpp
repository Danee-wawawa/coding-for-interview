/**
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == NULL){
			return res;
		}
		stack<TreeNode*> s;
		s.push(root);
		while (s.size()){
			TreeNode* tmp = s.top();
			s.pop();
			res.push_back(tmp->val);
			if (tmp->left != NULL)
				s.push(tmp->left);
			if (tmp->right != NULL)
				s.push(tmp->right);

		}
		reverse(res.begin(), res.end());
		return res;
	}
};