#define _CRT_SECURE_NO_WARNINGS 1
/*
��Ŀ����  ��ѧ��
Сv������n�ſΣ�ÿ�Ŷ��п��ԣ�Ϊ���õ���ѧ��Сv�������Լ���ƽ���ɼ�����Ϊ
avg��ÿ�ſ���ƽʱ�ɼ��Ϳ��Գɼ���ɣ�����Ϊr��������֪��ÿ�ſε�ƽʱ�ɼ�Ϊai ,
���������ſεĿ��Գɼ�����һ�ֵĻ���СvҪ��bi ��ʱ�临ϰ������ϰ�Ļ���Ȼ����0�֡�
ͬʱ������Ȼ���Է��ָ�ϰ���ٶ�Ҳ�����õ��������ֵķ�����Ϊ���õ���ѧ��Сv����Ҫ������ʱ�临ϰ��
��������:
��һ����������n,r,avg(n���ڵ���1С�ڵ���1e5��r���ڵ���1С�ڵ���1e9,avg���ڵ���1С�ڵ���1e6)��������n�У�ÿ����������ai��bi����С�ڵ���1e6���ڵ���1
�������:
һ������𰸡�
ʾ��1
����
����
5 10 9
0 5
9 1
8 1
0 1
9 100
���
����
43
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
̰�ģ���δ���������Ҹ�ϰ�¼���С�ģ���������������ƽ���֡�
��ǰƽ����>=avg����ֱ�ӷ���
*/
struct node{
	int score;//��ǰ��Ŀ�÷�
	int revise_time;//��ǰ��Ŀ����һ����Ҫ��ʱ�䣨�Դ���������
};
typedef node node;
//����
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
		if (count >= target){ cout << 0 << endl; continue; }//������ڵ�ǰƽ��ֵ���ø�ϰ
		//����
		sort(arr.begin(), arr.end(), cmp);
		for (int i = 0; i<n; ++i){
			//�ÿγ����������֣���ǰ�ܷ���
			count += (r - arr[i].score);
			if (count >= target){
				//��ǰ��������Ŀ��ɼ�˵���ÿγ̲�������Ҳ�����㽱ѧ������
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


//AVL�������������㷨��

//AVL���Ľ�㣺

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
	//����
	void rotateL(Node<T>* cur){
		//������ƽ����cur��L�Լ����Ƚ��
		node* Lcur = cur->left;
		node* grand = cur->parent;

		//��Lcur���Ҹ�cur����
		cur->left = Lcur->right;
		if (Lcur->right) Lcur->right->parent = cur;//��ֹLcur->right==NULL
		//Lcur���Ҹ�ֵΪcur
		Lcur->right = cur;
		cur->parent = Lcur;

		//�ж�cur֮ǰ�Ƿ�Ϊ�����
		if (grand == NULL){
			//����ǣ����ʱLcurΪ���ڵ�
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

	//����
	void rotateR(Node<T>* cur){
		node* Rcur = cur->right;
		node* RLcur = Rcur->left;
		node* grand = cur->parent;

		//��Rcur�����cur����
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

	//����˫�����ϸߵ�������ࣩ
	void RLrotate(node* cur){
		//����cur��������
		rotateR(cur->right);
		//����cur����
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