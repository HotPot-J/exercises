#define _CRT_SECURE_NO_WARNINGS 1

/*
1�������壨ţ�ͣ�
����һ�����̣��ж���û���������飨����5��Ҳ�㣩

����������
	�����ж������ݣ�ÿ������Ϊһ��20x20������
	���к����á�*����ʾ�������á�+����ʾ �հ���.��ʾ

���������
	��������ϴ����������飨����������ɫ�����ӣ������yes�������No
	
*/

/*
2��Emacs������
Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���
������ڲ��������档���磺2 3 + �ȼ���2+3
����ʵ��һ����׺���ʽ�ļ�����

����������
	���������������
	ÿ�����ݰ������У���һ����һ��������n(3<=n<=50)�������ŵڶ��а���n������ֵ�������
	��ɵ��б�
"+ - * /"

���������
	��Ӧÿһ�����ݣ�������ǵ�������

*/

/*
˼·:	�����ݴ��ڶ�queue�� 
		ÿ�γ��ӣ�
		1.������Ϊ���֣�ֱ�ӽ�stack
		2.������һ������� ֱ�Ӷ�ǰ�������ֽ������� Ȼ��pop���� ����������ջ
		3.����ջ��Ԫ�ؼ�Ϊ��
*/

#include<iostream>
#include<deque>
#include<stack>
#include<string>
using namespace std;

int main(){
	int n = 0;
	while (cin>>n){
		deque<string> q;
		stack<int> s;
		string tmp;
		for (int i = 0; i < n; ++i){
			cin >> tmp;
			q.push_back(tmp);
		}
		for (int i = 0; i < n; ++i){
			string a = q.front();
			q.pop_front();
			if (a == "+"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 + num2);
			}
			else if (a == "-"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num2 - num1);
			}
			else if (a == "*"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num1 * num2);
			}
			else if (a == "/"){
				int num1 = s.top();
				s.pop();
				int num2 = s.top();
				s.pop();
				s.push(num2 / num1);
			}
			else{
				int num = 0;
				for (size_t i = 0; i < a.size(); ++i){
					num = num * 10 + (a[i] - '0');
				}
				s.push(num);
			}
		}
		cout << s.top() << endl;
	}
	return 0;
}