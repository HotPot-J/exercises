#define _CRT_SECURE_NO_WARNINGS 1

/*
1���ַ�����
����һ���ַ�����������ַ����������ַ�������

����������ÿ����������һ���ַ������ַ����������Ϊ100����ֻ������ĸ��������Ϊ�մ������ִ�Сд

���������ÿ������һ�У������ַ���ԭ�е��ַ�˳������ַ����ϣ����ظ����ֲ��������ĸ
�������

����: 
 ����:abcqweracb
 ���:abcqwer
*/

/*
˼·:��ϣ
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
//int main(){
//	string str;
//	unordered_map<char, bool> m;
//	while (getline(cin, str)){
//		for (auto a : str){
//			m[a] = true;
//		}
//		for (auto b : str){
//			if (m[b]){
//				cout << b;
//				m[b] = false;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}

/*
2��Ԫ�ز���
��һ���Ź�������飬����n����������������������������һ�����ȵ�λ��
���磬ԭ����1��2��3��4��5��6 ����λ�����λ�ñ�Ϊ6��1��2��3��4��5 
���ڶ�����λ������飬��Ҫ����ĳ��λ�õ�Ԫ�أ������һ�����Ӷ�Ϊlog������㷨��ɸ�����
����һ��int����A��Ϊλ�ƺ�����飬ͬʱ���������Сn����Ҫ����Ԫ�ص�ֵx���뷵��x��λ��
��λ�ô�0��ʼ������֤������Ԫ�ػ���
���� ��6 1 2 3 4 5����6��6
*/

/*
˼·:���ֲ���
*/

//�ݹ�汾 ����ʱ������
class Finder {
public:
	int fun(vector<int> a, int i, int j,int x){
		int mid = (j - i) / 2;
		if (a[mid] == x){
			return mid;
		}
		if (a[mid] < x){
			if (a[mid]<a[i] && x>a[j]){
				//�ұ����� ����x>a[j] ��x�����������
				return fun(a, i, mid-1, x);
			}
			else{
				//�������
				return fun(a, mid+1, j, x);
			}
		}
		else{
			if (a[mid] > a[i] && x < a[i]){
				//������򣬵�x<a[i] ��x��������
				return fun(a, mid + 1, j, x);
			}
			else{
				return fun(a, i, mid - 1, x);
			}
		}
		return -1;
	}
	int findElement(vector<int> A, int n, int x) {
		return fun(A, 0, n - 1, x);
	}
};

//�����汾 ͨ��
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		int i = 0, j = n - 1, mid;
		while (i <= j) {
			mid = (i + j) / 2;
			if (A[mid] == x)
				return mid;
			if (A[mid]<x) {
				if (A[mid]<A[i] && x>A[j]) {
					j = mid - 1;
				}
				else{
					i = mid + 1;
				}
			}
			else {
				if (A[mid]>A[i] && x<A[i]){
					i = mid + 1;
				}
				else{
					j = mid - 1;
				}
			}
		}
		return -1;
	}
};
int main(){
	vector<int> A = { 6, 1, 2, 3, 4, 5 };
	Finder a;
	a.findElement(A, 6, 6);
	return 0;
}