#define _CRT_SECURE_NO_WARNINGS 1

/*
1�����Ĵ���һ�������ͷ�����һ�����ַ���������level����noon�ȵȾ��ǻ��Ĵ��������ǳ�ϲ������
���Ĵ����������յ���������ֱ�Ϊ�ַ���A��B�����ǳ�������û�а취���ַ���B�����ַ���A
ʹ�������ַ���Ϊ���Ĵ��������Ѱ���ж����ֲ���취����ʹ���´�Ϊ���Ĵ���
����:
	A = "aba" B = "b" �����ְ�B����A�İ취��
		baba ����
		abba��
		abba��
		abab����
		���Դ�Ϊ2

		���룺 ��һ��A �ڶ���B  �ַ������Ⱦ�С��100 ֻ����Сд��ĸ
		���: һ�����֣��𰸣�
*/
//˼·����Ҫ��ϰ��reverse����  ��string��Ա���� compare���ַ����Ƚϣ���substr���ַ�����ȡ������
//a.compare(b); ��a==b ����0   
//substr(0,3); ����ʼλ�ã�������ʼλ�õ��ַ�������3���ַ�
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool check(string s){
	//��֤����
	string tmp = s;
	reverse(s.begin(), s.end());
	if (tmp.compare(s) == 0){
		return true;
	}
	return false;
}
void fun(string A,string B){
	int res = 0;
	string tmp;
	tmp = B;
	tmp.append(A);
	if (check(tmp)){
		++res;
	}
	tmp.erase();
	for (int i = 0; i < A.size(); ++i){
		tmp += A.substr(0, i + 1);
		tmp += B;
		tmp += A.substr(i+1, A.size() - i-1);
		if (check(tmp)){
			++res;
		}
		tmp.erase();
	}
	cout << res << endl;
}
//int main(){
//	string A;
//	string B;
//	getline(cin, A);
//	getline(cin, B);
//	fun(A, B);
//	return 0;
//}

/*
2��һ��������N��Ԫ�أ�����������������ͣ�����:-1,2,1 �������������Ϊ[2��1] ���
Ϊ3
��������:
	����Ϊ���У���һ��һ������n(1<=n<=1000000)����ʾһ����N��Ԫ�أ��ڶ���ΪN���� ÿ����������int��Χ��
	����� ���������������к�����ֵ
*/

//˼·: ��̬�滮 ��������ǰ�����б�С���� ���Ӹ�λ�ÿ�ʼ���³���Ѱ��
#include<iostream>
#include<vector>
using namespace std;

	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 1){
			return nums[0];
		}
		int max = nums[0];
		for (int i = 1; i < nums.size(); ++i){
			int a = nums[i] + nums[i - 1];
			int b = nums[i];
			nums[i] = a>b ? a : b;
			if (nums[i] > max){
				max = nums[i];
			}
		}
		cout << max << endl;
	}

int  main(){
	int n = 0;
	int tmp = 0;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> tmp;
		arr.push_back(tmp);
	}
	maxSubArray(arr);
	return 0;
}