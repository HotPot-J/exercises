#define _CRT_SECURE_NO_WARNINGS 1


/*
1�����üӼ��˳����ӷ�
*/

/*
˼·:λ����  ��������:��λ�ñ�ʾ������λ�Ժ�Ľ�� ��a��ʾ
			 
			 ���������:��λֵ1��������˽�λ��0����δ������λ
			 ��ʱ�������Ľ������һλ���ý����b��ʾ ����ת��a+b
			 
			 �����������Ϊ0 ˵������λ�þ�Ϊ������λ �𰸼�Ϊ����Ľ��
	���ϣ��ݹ�������
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num2 == 0){
			return num1;
		}
		int tmp1 = num1^num2;
		int tmp2 = (num1&num2) << 1;
		return Add(tmp1, tmp2);
	}
};
//int main(){
//	int a = 0, b = 0;
//	while (cin >> a >> b){
//		Solution c;
//		cout << c.Add(a, b) << endl;
//	}
//	return 0;
//}


/*
2��������
���������ߣ������ж�һ���ܲ������һ��������
*/

/*
˼·�������ж� ��������֮�ʹ��ڵ�����
double�ķ�Χ��10^-308��10^308
*/
#include<iostream>
using namespace std;

int main()
{
	double a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b>c) && (a + c>b) && (b + c>a))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}