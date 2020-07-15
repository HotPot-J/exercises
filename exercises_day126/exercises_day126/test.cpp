#define _CRT_SECURE_NO_WARNINGS 1

/*
1��������Ӵ�
���ӣ�https://www.nowcoder.com/questionTerminal/02e7cc263f8a49e8b1e1dc9c116f7602
��Դ��ţ����
���������ַ����������һ��ʱ�临�Ӷ�ΪO(m*n)���㷨(�����m��nΪ�����ĳ���)��
���������������Ӵ��ĳ��ȡ������������Ӵ��Ķ���Ϊ��������U1,U2,..Un��
V1,V2,...Vn������Ui + 1 == Ui+1,Vi + 1 == Vi+1��ͬʱUi == Vi��
���������ַ���A��B��ͬʱ���������ĳ���n��m��
����������
	1ab2345cd 9  12345ef 7
*/

/*
˼·:��̬�滮
	1.i=0/j=0  dp[i][j] = 0
	2.x[j]=y[i] dp[i][j] = dp[i-1][j-1]+1
	2.x[j]!=y[i] dp[i][j] = 0 
	4.��Ҫ����maxȥ���½��
*/

class LongestSubstring {
public:
	int findLongest(string A, int n, string B, int m) {
		vector<vector<int>> dp;
		dp.resize(n + 1);
		for (size_t i = 0; i < n + 1; ++i){
			dp[i].resize(m + 1, 0);
		}
		int max = 0;
		for (size_t i = 1; i < n + 1; ++i){
			for (size_t j = 1; j < m + 1; ++j){
				if (A[i - 1] == B[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j]>max){
						max = dp[i][j];
					}
				}
				else{
					dp[i][j] = 0;
				}
			}
		}
		return max;
	}
};


/*
2�������������
�����������ַ���m��n��������ǵ��Ӵ�a��b������ͬ�����a��b��m��n�Ĺ��������С��Ӵ��е�
�ַ���һ����ԭ�ַ�����������
�����ַ���abcfbc��abfcab�����abc�����ǵĹ��������С�����ab af�������ǵ��Ӵ�
�ָ������������ַ���(�������ո�)�����æ�������ǵ�����������г���
����������
	��������������ݣ�ÿ�����ݰ��������ַ���m��n�����ǽ�������ĸ�����ҳ��Ȳ�����1024
���������
	��Ӧÿ�����룬�������������еĳ���
*/

/*
����Ϊ��̬�滮�ⷨ��
	��i��j = 0ʱ��dp[i][j] = 0
	��x[j]=y[i]   dp[i][j] = dp[i-1][i-1]+1
	��x[j]!=y[i]  dp[i][j] = max(dp[i-1][j],dp[i][j-1])
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	
	string a; string b;
	while (cin>>a>>b){
		size_t lenA = a.size(), lenB = b.size();
		vector<vector<int>> dp;
		dp.resize(lenA + 1);
		for (size_t i = 0; i < lenA+1; ++i){
			dp[i].resize(lenB + 1, 0);
		}
		for (size_t i = 1; i < lenA+1; ++i){
			for (size_t j = 1; j < lenB+1; ++j){
				if (a[i - 1] == b[j - 1]){
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		cout << dp[lenA][lenB] << endl;
	}
	return 0;
}

/*
�������������������е�˼·: ������dp
��x[j] = y[i] ���ַ���res j-1 i-1
����ѡ��max(dp[i-1][j],dp[i][j-1])������·��
*/