#define _CRT_SECURE_NO_WARNINGS 1

/*
1��������ǵı���

���������ξ��󣬵�һ��ֻ��һ����1�����µ�ÿ�е�ÿ������ǡ������������������Ͻǵ����Ͻǵ�����������֮��
(���������ĳ��������Ϊ����Ϊ0)
���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1.��������3�������2������4�����3
*/

/*
˼·:ͨ����ͼѰ�ҹ��ɣ�
	��n<3 ��ǰ���о�Ϊ1���������������-1 
	
	nΪ���� ��һ��ż���ڵڶ�λ
	
	nΪż�����ܱ�4���� �ڵ���λ
			 ���ܱ�4�����ڵ���λ
*/

#include<iostream>
using namespace std;
//
//int main(){
//	int n = 0;
//	while (cin>>n){
//		if (n < 3){
//			cout << -1 << endl;
//			continue;
//		}
//		if (n % 2 != 0){
//			//����
//			cout << 2 << endl;
//		}
//		else{
//			//ż��
//			if (n % 4 == 0){
//				cout << 3 << endl;
//			}
//			else {
//				cout << 4 << endl;
//			}
//		}
//	}
//	return 0;
//}

/*
2�������һ���㷨������������������ӷ�
�ӿ�˵��:
	���������
		string addend������
		string augend��������
	����ֵ���ӷ����
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int flag = 0;//��ʼ������λΪ0
		int ret = 0;
		string addret;
		int i = num1.size() - 1, j = num2.size() - 1;
		int size1 = i + 1, size2 = j + 1;
		while (size1&&size2){
			ret = (((num1[i] - '0') + (num2[j] - '0') + flag) % 10);
			addret += (ret + '0');
			//addret.insert(addret.begin(), ret+'0');//ͷ���ȥ �Ͳ��÷�ת��
			flag = (((num1[i--] - '0') + (num2[j--] - '0') + flag) / 10);
			size1--;
			size2--;
		}
		while (size1){
			//��num1����ʣ���λ��
			ret = (((num1[i] - '0') + flag) % 10);
			addret += (ret + '0');
			//addret.insert(addret.begin(), ret + '0');
			flag = (((num1[i--] - '0') + flag) / 10);
			size1--;
		}
		while (size2){
			//��num2����ʣ���λ��
			ret = (((num2[j] - '0') + flag) % 10);
			addret += (ret + '0');
			//addret.insert(addret.begin(), ret + '0');
			flag = (((num2[j--] - '0') + flag) / 10);
			size2--;
		}
		if (flag){

			addret += (flag + '0');
			//addret.insert(addret.begin(), flag+ '0');
		}
		reverse(addret.begin(), addret.end());
		return addret;
	}
};
int main(){
	Solution a;
	string num1, num2;
	while (cin >> num1 >> num2){
		cout<<a.addStrings(num1,num2)<<endl;
	}
	return 0;
}
