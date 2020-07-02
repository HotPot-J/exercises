#define _CRT_SECURE_NO_WARNINGS 1

/*
1������λ�ϵĶ���������ż��λ�ϵĶ���ż��
�ڸ���һ�����Ȳ�С��2����ֵarr��дһ����������arr��ʹ��arr��Ҫô��������λ�϶���������
Ҫô����ż��λ�϶���ż����ʱ�临�Ӷ�λO��N�� �ռ临�Ӷ�O��1�� �±�0��2��4λżλ��1 3 7
Ϊ����λ������[1 2 3 4]������ [2 1 4 3]����
*/

/*
˼·�� ˫ָ��  һ����Զָ������λodd һ����Զָ��ż��λ even
1.��oddָ�������Ϊż��evenָ���Ϊ�棬ֱ�ӻ���
2.��oddָ��ż��evenΪż����even�������� ָ����һ��ż��λ add����
3.��oddָ���棬evenָ���棬��odd�������� ָ����һ������λ even����
4.����������˫ָ���������
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int even = 0, odd = 1;
		while (even < len&&odd < len){
			//���1��
			if (arr[even] % 2 != 0 && arr[odd] % 2 == 0){
				swap(arr[even], arr[odd]);
				even += 2;
				odd += 2;
			}
			//���2��
			else if (arr[even] % 2 == 0 && arr[odd] % 2 == 0){
				even += 2;
			}
			//���3��
			else if (arr[even] % 2 != 0 && arr[odd] % 2 != 0){
				odd += 2;
			}
			//���4��
			else{
				even += 2;
				odd += 2;
			}
		}
	}
};

//int main(){
//	vector<int> a = { 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 };
//	Solution b;
//	b.oddInOddEvenInEven(a, 4);
//	return 0;
//}

/*
2�����ӷ��� ţ��
*/

/*
˼·�� nֻС���� �������m������  ���ڸ����ӷ���ÿ�ζ�������һ�� ��m+4���ñ�5����
��һ��С�����õļ����Ϻ��ӵ���һ������ = ��m+4��*(1/5)  ʣ�� ��m+4��*��4/5��
�ڶ���С��������1/5�� ʣ�ࣨm-4��*��4/5��^2
...
��n��С��������1/5��  ʣ�ࣨm-4��*��4/5��^n
����(m-4)*��4/5��^n ���Ա�5���� ���Ըý��Ϊ��������� ��m-4�� = 5^n�����
	��ô m = 5^n-4�����
	�Ϻ������տɻ��:��m-4��*��4/5��^n + n -4 = 4^n+n-4 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			break;
		}
		long m = pow(double(5), double(n)) - 4;
		long oldM = pow(double(4), double(n)) + n - 4;
		cout << m << " " << oldM << endl;
	}
	return 0;
}