#define _CRT_SECURE_NO_WARNINGS 1

/*
1.΢�ź��
�����ڼ䣬С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ��������
���ֵĴ��������˺��������һ�롣���С���ҵ��ú���������㷨˼·�ʹ���ʵ�֣�Ҫ��
�����ܸ�Ч������һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ���û�н��
��������һ�룬����0
*/

/*
˼·��Ѱ�ҳ���������һ�����ֵı��� ������������п���û�г���һ���
���򣬻�������Ѱ�ҳ�������������
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		sort(gifts.begin(), gifts.end());
		int i = 0, j = 0, count = 0;
		for (int i = 0; i < n; ++i){
			for (j = i + 1; j < n; ++j){
				if (gifts[i] != gifts[j]){
					count = (j - i)>count ? (j - i) : count;
					if (count>n / 2){
						return gifts[i];
					}
					break;
				}
			}
		}
		return 0;
	}
};

//int main(){
//	vector<int> arr;
//	Gift a;
//	int tmp = 0, n = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	cout << a.getValue(arr, n) << endl;
//	return 0;
//}

/*
2.�����ַ����ľ���
levenshtein���룬�ֳ�Ϊ�༭���룬ָ���������ַ���֮�䣬��һ��ת������һ������Ҫ������
�༭������������ɵı༭����������һ���ַ��滻����һ���ַ�������һ���ַ���ɾ���ַ���
�༭������㷨�������ɶ����ѧ��levenshtein����ġ�
�ַ���A��abcdefg
�ַ���B��abcdef
���ӻ���ɾ��g�����ԴﵽĿ�ģ�����ֻ��Ҫһ�β����������1����Ϊ����
*/

/*
˼·��dfs ����  
��˼·ʵ���� ���ǿռ�ʱ�临�Ӷȹ��� �޷�AC....
*/
#include<iostream>
#include<string>
using namespace std;
void dfs(string a, string b,size_t i,size_t j, int tmp, int& res){
	if (i >= a.size()){
		if (j < b.size()){
			tmp += b.size() - a.size();
		}
		if (res == 0 && tmp != 0){
			res = tmp;
			return;
		}
		res = tmp < res ? tmp: res;
		return;
	}
	else if (j >= b.size())
	{
		if (i < a.size()){
			tmp += a.size() - b.size();
		}
		if (res == 0 && tmp != 0){
			res = tmp;
			return;
		}
		res = tmp < res ? tmp : res;
		return;
	}

	//�滻��·
	if (a[i] != b[j]){
		char c = a[i];
		a[i] = b[i];
		int tmp1 = tmp;
		++tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		//���� ע�� tmpҲ��Ҫ���л���
		a[i] = c;
		tmp = tmp1;
	}
	//�����·
	if (a[i] != b[j]&&j+1<b.size()&&a[i]==b[j+1]){
		a.insert(i, 1, b[j]);
		++tmp;
		int tmp1 = tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		a.erase(i, 1);
		tmp = tmp1;
	}
	//ɾ����·
	if (a[i] != b[j] && j + 1 < b.size() && a[i] == b[j + 1]){
		char c = b[j];
		b.erase(j, 1);
		int tmp1 = tmp;
		++tmp;
		dfs(a, b, i + 1, j + 1, tmp, res);
		b.insert(j, 1, c);
		tmp = tmp1;
	}
	dfs(a, b, i + 1, j + 1, tmp, res);
}
//int main(){
//	string A, B;
//	while (cin >> A >> B){
//		int res = 0;
//		string a, b;
//		if (A.size() > B.size()){
//			 a = B;
//			 b = A;
//		}
//		else{
//			a = A;
//			b = B;
//		}
//		dfs(a, b, 0, 0, 0, res);
//		cout << res << endl;
//	}
//	return 0;
//}

/*
˼·2����̬�滮
 ��aiΪ�ַ���A(a1a2a3....ai)��ǰi���ַ�
   bjΪ�ַ���B(b1b2b3....bj)��ǰj���ַ�
 if(ai==bj) f(i,j) = f(i-1,j-1)
 
 if(ai!=bj)
	1.ѡ���滻�������ַ�������Ҫ���� f(i-1,j-1)��
	2.ѡ��ɾ��ai������bj�����ai ����Ҫ����f(i-1��j)
	3.ѡ��ɾ��bj������ai�����bj ����Ҫ����f(i,j-1)
	��ʱ f(i,j) = min��f��i-1��j-1����f(i-1,j),f(i,j-1)��+1
	f(0,j) = j,f(i,0) = i
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int _dp(string& a,string& b,int& n1,int& n2,vector<vector<int>>& dp){
	for (int i = 1; i < n1; ++i){
		for (int j = 1; j < n2; ++j){
			if (a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	return dp[n1 - 1][n2 - 1];
}
int main(){
	string A, B;
	while (cin >> A >> B){
		vector<vector<int>> dp;
		int n1 = A.size()+1, n2 = B.size()+1;
		dp.resize(n1);
		for (int i = 0; i < n1; ++i){
			dp[i].resize(n2, 0);
		}
		//f(i,0) = i;
		for (int i = 0; i < n1; ++i){
			dp[i][0] = i;
		}
		//f(0,j) = j
		for (int j = 0; j < n2; ++j){
			dp[0][j] = j;
		}
		cout << _dp(A, B, n1, n2, dp) << endl;
	}
	return 0;
}