#define _CRT_SECURE_NO_WARNINGS 1

/*
1��Fibnacci��������������ģ�
 F[0] = 0
 F[1] = 1
 for eachi>=2 : F[i] = F[i-1]+F[i-2]
 ��� 쳲���������:0 1 1 2 3 5 8 13...����쳲����������е������ǳ�֮Ϊ쳲���������
 ����һ������N�����������Ϊһ��Fibonacci��ÿһ������԰ѵ�ǰ������X��ΪX-1����X+1����
 ����һ����N����������Ҫ���ٲ����Ա�Ϊ쳲���������
 ��������: 
	����Ϊһ������(1<=1 000 000)
 ���������
	����һ����С�Ĳ�����Ϊ쳲�������
ʾ����
	15
��� 2
*/

//˼·: �����ų��ݹ�ȥд쳲����������ɱ�̫�ߣ������� F[i] = F[i-1]+F[i-2]�ĵ��ƹ�ʽȥ��쳲�����
//���д���һ�������У���Ѱ�ҵ� F[i]<= N <=F[i](��=ʱ�������Ϊ0��)��Ȼ��������ֵ ȡ��С��Ϊ���
#include<iostream>
#include<vector>
using namespace std;
int Fibonacci(int N){
	vector<int> arr;
	arr.resize(1000000);
	arr[0] = 0;
	arr[1] = 1;
	int i = 2;
	if (N == 0 || N == 1){
		return 0;
	}
	while (1){
		arr[i] = arr[i - 1] + arr[i - 2];
		if (arr[i - 1] <= N&&arr[i] >= N){
			//N������֮��
			if (arr[i - 1] == N || arr[i] == N){
				return 0;
			}
			int a = N - arr[i - 1];
			int b = arr[i] - N;
			return a < b ? a : b;
		}
		++i;
	}
}
//int main(){
//	int N = 0;
//	cin >> N;
//	cout << Fibonacci(N) << endl;
//	return 0;
//}

/*
2������һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
һ���Ϸ������Ŵ�����Ϊ:1.ֻ���������ַ���2.�����ź�������һһ��Ӧ
����:
	"(()())",6
	���أ�true

	"()a()()",7
	���أ�false

	"()(()()",7
*/

//˼·һ��ʹ��ջ������� �ַ���A��Ԫ��������ջƥ����ֱ�ӳ�ջ ����ջΪ����ȫ��ƥ��ɹ�
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		if (A.size() <= 0){
			return false;
		}
		stack<char> tmp;
		char* str = (char*)A.c_str();
		while (*str){
			if (*str != '('&&*str != ')'){
				return false;
			}
			if (tmp.empty()){
				tmp.push(*str);
			}
			else{
				if (*str == ')'&&tmp.top() == '('){
					//ƥ����һ��
					tmp.pop();
				}
				else if (*str == '('&&tmp.top() == '('){
					tmp.push(*str);
				}
			}
			++str;
		}
		if (tmp.empty()){
			return true;
		}
			return false;
	}
};

int main(){
	string s = "()(()()";
	Parenthesis a;
	a.chkParenthesis(s, 0);
	return 0;
}