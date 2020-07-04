#define _CRT_SECURE_NO_WARNINGS 1

/*
1�����ѵ����� ��ţ�ͣ�
*/

/*
˼·:  �������֪ һ����ĸ��ǰ5�� ���Լ��ĵں�21����ĸ
*/

#include <iostream>
//#include <string>
//using namespace std;

//int main() {
//	string password;
//	while (getline(cin,password)){
//		size_t len = password.size();
//		for (size_t i = 0; i < len; ++i){
//			if (isupper(password[i])){
//				password[i] = (password[i] - 'A' + 21) % 26+'A';
//			}
//		}
//		cout << password << endl;
//	}
//	return 0;
//}

/*
2�����Ӹ��� ��ţ�ͣ�
*/

/*
˼·���������� ÿ������ӦΪ���� ֻ��Ҫ�жϵ�ǰ������������������n����++res
     dfs���� 
*/

#include<iostream>
#include<vector>
using namespace std;

bool check(int n)
{
	if (n < 2){
		return false;
	}
	if (n == 2){
		return true;
	}
	if (n % 2 == 0){
		return false;
	}
	for (int i = 3; i*i <= n; i += 2) {
		if (n%i == 0){
			return false;
		}
	}
	return true;
}

void dfs(int n,int begin,int& res){
	if (check(n)){
		//���nҲ�Ǹ����� ���ҵ������е�������
		//��Ȼ��ʱ��nҲ����һ��������
		++res;
		return;
	}

	for (int i = begin; i < n; ++i){
		if (check(i)&&n%i==0){
			//i����������Լn
			++res;
			while (n%i == 0){
				//���˵���������
				n /= i;
			}
			dfs(n, begin + 1, res);
			//�����е�n���������Ѿ����˵��� ֱ�ӷ��ؼ���
			return;
		}
	}
}

int main(){
	int n = 0;
	while (cin >> n){
		int res = 0;
		dfs(n, 2, res);
		cout << res << endl;
	}
	return 0;
}