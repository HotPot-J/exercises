#define _CRT_SECURE_NO_WARNINGS 1
/*
题目描述  奖学金
小v今年有n门课，每门都有考试，为了拿到奖学金，小v必须让自己的平均成绩至少为
avg。每门课由平时成绩和考试成绩组成，满分为r。现在他知道每门课的平时成绩为ai ,
若想让这门课的考试成绩多拿一分的话，小v要花bi 的时间复习，不复习的话当然就是0分。
同时我们显然可以发现复习得再多也不会拿到超过满分的分数。为了拿到奖学金，小v至少要花多少时间复习。
输入描述:
第一行三个整数n,r,avg(n大于等于1小于等于1e5，r大于等于1小于等于1e9,avg大于等于1小于等于1e6)，接下来n行，每行两个整数ai和bi，均小于等于1e6大于等于1
输出描述:
一行输出答案。
示例1
输入
复制
5 10 9
0 5
9 1
8 1
0 1
9 100
输出
复制
43
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
贪心：让未到达满分且复习事件较小的，拉满，以提升总平均分。
当前平均分>=avg，则直接返回
*/
struct node{
	int score;//当前科目得分
	int revise_time;//当前科目提升一分需要的时间（以此来升排序）
};
typedef node node;
//升序
bool cmp(node a, node b){
	return a.revise_time<b.revise_time;
}

int main(){
	int n = 0, r = 0, avg = 0;
	while (cin >> n >> r >> avg){
		long res = 0;
		int target = n*avg;
		vector<node> arr(n);
		int count = 0;
		for (int i = 0; i<n; ++i){
			cin >> arr[i].score;
			cin >> arr[i].revise_time;
			count += arr[i].score;
		}
		if (count >= target){ cout << 0 << endl; continue; }//如果大于当前平均值则不用复习
		//排序
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i<n; ++i){
			//该课程如果获得满分，求当前总分数
			count += (r - arr[i].score);
			if (count >= target){
				//当前分数超过目标成绩说明该课程不得满分也可满足奖学金条件
				count -= (r - arr[i].score);
				res += (target - count)*arr[i].revise_time;
				cout << res << endl;
				break;
			}
			else{
				res += (r - arr[i].score)*arr[i].revise_time;
			}
		}
	}
	return 0;
}


//AVL树的左旋右旋算法：

//AVL树的结点：

template<class T>
struct Node{
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	T val;
	int _bf;
};


template<class T>
class AVLtree{
	typedef Node<T> node;
	node* _root;
	//右旋
	void rotateL(Node<T>* cur){
		//保留不平衡结点cur的L以及祖先结点
		node* Lcur = cur->left;
		node* grand = cur->parent;

		//将Lcur的右给cur的左
		cur->left = Lcur->right;
		if (Lcur->right) Lcur->right->parent = cur;//防止Lcur->right==NULL
		//Lcur的右赋值为cur
		Lcur->right = cur;
		cur->parent = Lcur;

		//判断cur之前是否为根结点
		if (grand == NULL){
			//如果是，则此时Lcur为根节点
			_root = Lcur;
			Lcur->parent = NULL;
		}
		else{
			if (grand->left == cur){
				grand->left = Lcur;
			}
			else{
				grand->right = Lcur;
			}
			Lcur->parent = grand;
		}
		cur->_bf = Lcur->_bf = 0;
	}

	//左旋
	void rotateR(Node<T>* cur){
		node* Rcur = cur->right;
		node* RLcur = Rcur->left;
		node* grand = cur->parent;

		//将Rcur的左给cur的右
		cur->right = RLcur;
		if (RLcur) RLcur->parent = cur;

		Rcur->left = cur;
		cur->parent = Rcur;

		if (grand == NULL){
			_root = Rcur;
			Rcur->parent = NULL;
		}
		else{
			if (grand->left){
				grand->left = Rcur;
			}
			else{
				grand->right = Rcur;
			}
			Rcur->parent = grand;
		}
		cur->_bf = Rcur->_bf = 0;
	}

	//右左双旋（较高的子树左侧）
	void RLrotate(node* cur){
		//先让cur的右右旋
		rotateR(cur->right);
		//再让cur左旋
		ratateL(cur);

		if (bf == -1){
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1){
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0){
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}
};