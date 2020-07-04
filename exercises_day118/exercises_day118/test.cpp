#define _CRT_SECURE_NO_WARNINGS 1

/*
1、最难的问题 （牛客）
*/

/*
思路:  由题意可知 一个字母的前5个 即自己的第后21个字母
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
2、因子个数 （牛客）
*/

/*
思路：根据题意 每个因子应为质数 只需要判断当前因子是质数且能整除n，则++res
     dfs即可 
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
		//如果n也是个质数 则找到了所有的质因子
		//当然此时的n也算作一个质因子
		++res;
		return;
	}

	for (int i = begin; i < n; ++i){
		if (check(i)&&n%i==0){
			//i是质数且能约n
			++res;
			while (n%i == 0){
				//过滤掉该质因子
				n /= i;
			}
			dfs(n, begin + 1, res);
			//此论中的n的质因子已经过滤掉了 直接返回即可
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