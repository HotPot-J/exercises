#define _CRT_SECURE_NO_WARNINGS 1

/*
1�������Ʋ���
������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�ĵĶ����Ƶĵ�j����iλ��
���ж����Ƶ�λ���ӵ�λ����λ��0��ʼ��
����������int n�� int m��ͬʱ����int j����int i�����������������뷵�ز��������
��֤n�ĵ�j����iΪ��Ϊ0����m�Ķ�����λ��С��i-j+1
������
	1024��19��2��6
	���أ�1100
*/

/*˼· λ���� ��m����jλ��n����|���㼴��
1024��	100 0000 0000   19��1 0011
             100 11			  
*/
#include<iostream>
using namespace std;
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		n |= m;
		return n;
	}
};

//int main(){
//	BinInsert a;
//	cout<<a.binInsert(1024, 19, 2, 6)<<endl;
//	return 0;
//}

/*
2���������һ��ż����ӽ�����������
�κ�һ��ż��(����2)��������������������ɣ����ż����2�������кܶ������������ĿҪ��
������ָ��ż��������������ֵ��С�������ԡ�
���룺һ��ż��  20

������������� 7
			   13
*/

/*
˼·: �������⣬��ż�����Զ���ͬʱͬ������ʹ���ȥѰ�� �������Ҿ�Ϊ���� ����������
*/

#include<iostream>
using namespace std;
bool fun(int x){
	int tmp = x / 2;
	for (int i = 2; i <= tmp; ++i){
		if (x%i == 0){
			return false;
		}
	}
	return true;
}
void find_(int n){
	int mid = n / 2;
	int left = mid, right = mid;
		while (1)
		{
			if (fun(left) && fun(right)){
				break;
			}
			left--;
			right++;
		}
		cout << left << endl;
		cout << right << endl;
		
}

//int main(){
//	int n = 0;
//	while (cin >> n){
//		find_(n);
//	}
//	return 0;
//}

