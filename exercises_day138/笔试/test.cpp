#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Ա����̨��
*/
/*
f(i) = f(i-1)+f(i-2)
*/
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			cout << 0 << endl;
		}
		else{
			vector<int> dp(n + 1, 0);
			//��ʼ״̬
			dp[0] = 1;
			dp[1] = 1;//�����һ��̨��ֻ��һ�ַ���
			for (int i = 2; i <= n; ++i){
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			cout << dp[n] << endl;
		}
	}
	return 0;
}

//int fun(int n){
//	if (n == 0 || n == 1){
//		return 1;
//	}
//	return fun(n - 1) + fun(n - 2);
//}
//
//int main(){
//	int n = 0;
//	while (cin >> n){
//		if (n==0||n > 36){ cout << 0 << endl; }
//		else{
//			cout << fun(n) << endl;
//		}
//	}
//}

/*
��Ǩ������һ�ŷ���Ҫ�𣬱�֤ÿһ�������ٷ�һ�ס�
1.���ڷ��ӣ����˶�ķ���ķ��Ӵ����ٵġ�
2.������ͬ��ס���������Ƿ����� �ֵ��ķ��Ӷ����Բ�ͬ
�����ٷ��䷿�ӵķ���
*/
/*
��arr[i-1]<arr[i]: f(i) = f(i-1)+1
��arr[i-1]>arr[i]: s) = f(i)+1
��ʼ״̬��ÿ�����ȷ�һ�׷��� ��֤���ٷ�һ��
*/

class Solution {
public:
	int house(int* person, int personLen) {
		if (personLen == 0 || person == NULL){ return 0; }
		if (personLen == 1){ return 1; }
		vector<int>dp(personLen + 1, 1);
		for (int i = 2; i <= personLen; ++i){
			if (person[i - 1] == 0){
				dp[i] = 0;
			}
			else if (person[i - 2] < person[i - 1]){
				dp[i] = dp[i - 1] + 1;
			}
			else if (person[i - 2] > person[i - 1]){
				dp[i - 1] = dp[i] + 1;
			}
		}
		long res = 0;
		for (int i = 1; i <= personLen; ++i){
			res += dp[i];
		}
		return res;
	}
};

//int main(){
//	int arr[3] = { 3,2,4};
//	Solution a;
//	a.house(arr, 3);
//	return 0;
//}

/*
1.�ҳ�һ���ַ����ܱ��ֳɶ��ٷݡ�
���磺aaabbbcc
��3��aaa��+3��bbb��+2��cc����/3 = 2 
*/
class Solution {
public:
	/**
	* �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	*
	* @param str string�ַ���
	* @return int����
	*/
	int GetFragment(string str) {
		if (str.empty()){ return 0; }
		vector<int> res;
		int a = 0, i = 0;
		while (i<str.size()){
			int tmp = 0;
			++i;
			++tmp;
			while (i < str.size() && str[i] == str[i - 1]){
				++i;
				++tmp;
			}
			a += tmp;
			res.push_back(tmp);
		}
		return a / res.size();
	}
};

//int main(){
//	string s = "aaabbaaac";
//	Solution2 a;
//	a.GetFragment(s);
//	return 0;
//}

/*
������ 17.16. ��Ħʦ
һ�������İ�Ħʦ���յ�ԴԴ���ϵ�ԤԼ����ÿ��ԤԼ������ѡ��ӻ򲻽ӡ���ÿ��ԤԼ����֮��Ҫ����Ϣʱ�䣬
��������ܽ������ڵ�ԤԼ������һ��ԤԼ�������У��水Ħʦ�ҵ����ŵ�ԤԼ���ϣ���ԤԼʱ������������ܵķ�������
ע�⣺�������ԭ�������Ķ�
ʾ�� 1��

���룺 [1,2,3,1]
����� 4
���ͣ� ѡ�� 1 ��ԤԼ�� 3 ��ԤԼ����ʱ�� = 1 + 3 = 4��
ʾ�� 2��

���룺 [2,7,9,3,1]
����� 12
���ͣ� ѡ�� 1 ��ԤԼ�� 3 ��ԤԼ�� 5 ��ԤԼ����ʱ�� = 2 + 9 + 1 = 12��
ʾ�� 3��

���룺 [2,1,4,5,3,1,1,3]
����� 12
���ͣ� ѡ�� 1 ��ԤԼ�� 3 ��ԤԼ�� 5 ��ԤԼ�� 8 ��ԤԼ����ʱ�� = 2 + 4 + 3 + 3 = 12��
*/
/*
˼·����̬�滮
Ŀ�꣺��ԤԼ��ʱ�����
�����⣬״̬��f(i)����i��β���ԤԼʱ��
���������Ĳ���һ��ԤԼ�����ǲ�����Ķ��������ԣ�
f(i) = j<i&&max(f(i),f(j)+arr[i])
*/
class Solution {
public:
	int massage(vector<int>& nums) {
		if (nums.empty()){ return 0; }
		vector<int> dp(nums.size() + 2, 0);
		int res = INT_MIN;
		for (int i = 2; i<nums.size() + 2; ++i){
			for (int j = 0; j<i - 1; ++j){
				//��֤j<i-1(������)
				dp[i] = max(dp[i], dp[j] + nums[i - 2]);
			}
			if (dp[i]>res){ res = dp[i]; }
		}
		return res;
	}
};