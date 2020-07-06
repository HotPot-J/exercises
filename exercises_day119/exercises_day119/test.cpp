#define _CRT_SECURE_NO_WARNINGS 1

/*
1.分解因数
*/

/*
思路：递归
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

void dfs(int n, int begin, vector<int>& res){
	if (check(n)){
		//如果n也是个质数 则找到了所有的质因子
		//当然此时的n也算作一个质因子
		res.push_back(n);
		return;
	}

	for (int i = begin; i < n; ++i){
		if (check(i) && n%i == 0){
			//i是质数且能约n
			while (n%i == 0){
				//过滤掉该质因子
				res.push_back(i);
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
		vector<int> res;
		dfs(n, 2, res);
		cout << n << " = ";
		for (size_t i = 0; i < res.size(); ++i){
			if (i == res.size() - 1){
				cout << res[i];
			}
			else{
				cout << res[i] << " * ";
			}
		}
		cout << endl;
	}
	return 0;
}
