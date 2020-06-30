#define _CRT_SECURE_NO_WARNINGS 1

/*
1����̬��̨��
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��....��Ҳ��������n�����������
����һ��n��̨���ж����ַ���
*/


/*
˼·������+��֦  ��������leetcode 39.�����ܺ����� ֻ����������� �������1-n��
��ֻ���㷽���������ر������巽��,������Ҫÿһ�ַ������磺��1 2�� ��2 1������������ ���Բ���Ҫ�������������ƣ���֦��
ֻ��Ҫ�٣�number-i<0��ʱ����м�֦���ɣ�
��
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int _res = 0;
	int jumpFloorII(int number) {
		dfs( number,number);
		return _res;
	}
	void dfs(int number,int n){
		if (number == 0){
			//�ҵ����н�
			++_res;
			return;
		}
		for (int i = 1 ; i <= n; i++){
			if (number - i < 0){
				//��֦ ��ǰn-iС��0 ��ô��ߵ�����Ҳ����������
				break;
			}
			number -= i;
			dfs(number,n);
			//����
			number += i;
		}
	}
};

//int main(){
//	Solution a;
//	cout<<a.jumpFloorII(3)<<endl;
//	return 0;
//}

/*
2���쵽������
С���Ǻ�ϲ�����Լ�װ��������(������)������Ҫ������ܳ����������̣����Ǿͽ���ȥ��
���ڸ��������ǵ�������İ뾶�����ж��ܷ�����ȥ��

���룺
	�������� n( 1<=n<=2^128) r( 1<=r<=2^128)  �ֱ��������������İ뾶
	Բ����3.14
���:
	�ܽ������YES ���ܾ�NO
*/

/*
˼·: ����Ӧ����long double ���бȽ� int�����
*/

#include<iostream>
using namespace std;
int main()
{
	long double n;
	long double r;
	while (cin >> n >> r)
	{
		if (n <= 2 * 3.14*r)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}