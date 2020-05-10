#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
/*
236. �������������������
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x������ x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶�����:  root = [3,5,1,6,2,0,8,null,null,7,4]





ʾ�� 1:

����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
���: 3
����: �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��
*/



struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* ans;
	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return false;
		bool lson = dfs(root->left, p, q);
		bool rson = dfs(root->right, p, q);
		if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
			ans = root;
		}
		return lson || rson || (root->val == p->val || root->val == q->val);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p, q);
		return ans;
	}
};

