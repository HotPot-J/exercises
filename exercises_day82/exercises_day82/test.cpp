﻿#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std; 

/*
给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入:
二叉树如下所示:
4
/   \
2     6
/ \   /
3   1 5

v = 1

d = 2

输出:
4
/ \
1   1
/     \
2       6
/ \     /
3   1   5

示例 2:

输入:
二叉树如下所示:
4
/
2
/ \
3   1

v = 1

d = 3

输出:
4
/
2
/ \
1   1
/     \
3       1
注意:

输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
输入的二叉树至少有一个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-one-row-to-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void dfs(TreeNode* root, int v, int d, int k) {
		if (root == NULL) return;
		if (k == d - 1) {
			TreeNode* lnode = new TreeNode(v);
			TreeNode* rnode = new TreeNode(v);
			lnode->left = root->left;
			rnode->right = root->right;
			root->left = lnode;
			root->right = rnode;
			return;
		}
		dfs(root->left, v, d, k + 1);
		dfs(root->right, v, d, k + 1);
	}
	TreeNode* addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode* node = new TreeNode(v);
			node->left = root;
			return node;
		}
		dfs(root, v, d, 1);
		return root;
	}
};

