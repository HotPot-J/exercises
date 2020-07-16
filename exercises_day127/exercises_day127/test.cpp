#define _CRT_SECURE_NO_WARNINGS 1

/*
1�����ʼ�
���ӣ�https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
��Դ��ţ����

NowCoderÿ��Ҫ���ܶ��˷��ʼ�����һ�������ַ������ʼ����ѷ���A���ʼ�������B��
�ѷ���B���ʼ�������A����������˼����Ҫ��n���˷��ʼ�����ÿ���˽��յ�1���ʼ�������£�
�ж���������������˶��յ��˴�����ʼ���
��û�����յ������Լ����ʼ���

��������:
��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����


�������:
��Ӧÿһ�����ݣ����һ������������ʾ�����յ��Լ��ʼ���������
*/

/*
˼·:�ݹ� �ŵ���ͣ�
	1.��ÿ�ζ������ڵļĴ��������������Ϊ����n-1)*f(n-2)
	2.���򣺣�n-1)*f��n-1��
	�ɵõ��ƹ�ʽΪf��n�� = ��n-1��*��f��n-1��f��n-2����
*/

#include<iostream>
using namespace std;

//�󷢴��¼���������

long long fun(long long n){
	if (n == 1){
		return 0;
	}
	if (n == 2){
		return 1;
	}
	return (n - 1)*(fun(n - 1) + fun(n - 2));
}

//int main(){
//	long long n = 0;
//	while (cin >> n){
//		cout << fun(n) << endl;
//	}
//	return 0;
//}


/*
2��
���ӣ�https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
��Դ��ţ����

�����]�����������

�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ�
�����æ�ҳ�������ε����������С� ����������������ǣ�1��7��3��5��9��4��8����
�������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��

��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000����
�����ŵڶ��а���n��������m��1��n��10000�������������ÿλ��Ա����ߡ�

�������:
��Ӧÿһ�����ݣ��������������еĳ��ȡ�

����:
  ���룺  7
		  1 7 3 5 9 4 8
  ����� 4    ����1 3 5 9��
*/

/*
˼·:��̬�滮
	1.��arr[i]>arr[j]	dp[i] = max(dp[i],dp[j]+1);
	2.ÿ�θ������ֵ
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n = 0;
	while (cin>>n){
		vector<int> arr;
		vector<int> dp;
		dp.resize(n, 0);
		int tmp = 0;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			arr.push_back(tmp);
		}
		int res = 0;
		for (int i = 1; i < n; ++i){
			for (int j = 0; j < i; ++j){
				if (arr[i]>arr[j]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
				if (dp[i]>res){
					res = dp[i];
				}
			}
		}
		cout << res + 1 << endl;
	}
	return 0;
}