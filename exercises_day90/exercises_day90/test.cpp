#define _CRT_SECURE_NO_WARNINGS 1

/*
1、A,B,C三个人是好朋友，每个人手里都有一些糖果，我们不知道他们每个人手上具体有多少个
糖果，有以下信息:
	A-B,B-C,A+B,B+C这四个数值。每个字母代表每个人拥有的糖果数。现在需要通过这四个数值
	计算出每个人手里有多少个糖果，即A,B,C 这里保证做多只有一组整数满足题设条件

输入描述:
	输入为一行，一共四个整数，分别为A-B,B-C,A+B,B+C （-30至30的闭区间）
输出描述:
	输出为一行，如果存在满足的整数A,B,C则按照顺序输出A,B,C不存在就输出No
例子：	1 -2 3 4
		2 1 3
*/

//思路：二元一次方程组

#include<iostream>
#include<vector>
using namespace std;
void fun1(vector<int>& arr){
	vector<int> res;
	int A = (arr[0] + arr[2])/2;
	int B = (arr[1] + arr[3]) / 2;
	int C = 0;
	if ((A - B) == arr[0] && (A + B) == arr[2]){
		//证明了A B间关系符合条件
		res.push_back(A);
		res.push_back(B);
		//证明C
		C = (arr[3] - arr[1]) / 2;
		if (B - C == arr[1] && B + C == arr[3]){
			res.push_back(C);
			for (int i = 0; i < 3; ++i){
				cout << res[i] << " ";
			}
		}
		else{
			cout << "No" << endl;
		}
	}
	else{
		cout << "No" << endl;
	}
}
//int main(){
//	vector<int> arr;
//	int tmp = 0;
//	for (int i = 0; i < 4; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	fun1(arr);
//	return 0;
//}

/*
2、给定一个十进制数M，以及需要转换进制数N。讲十进制数M转换为N进制数
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int arr[2] = {0,0};
	string res, tmp = "0123456789ABCDEF";
	for (int i = 0; i < 2; ++i){
		cin >> arr[i];
	}
	if (arr[0] == 0){
		cout << "0" << endl;
	}
	else{
		while (arr[0]){
			if (arr[0] < 0){
				arr[0] = -arr[0];
				cout << "-";
			}
			res = tmp[arr[0] % arr[1]] + res;
			arr[0] /= arr[1];
		}
	}
	cout << res;
	return 0;
}

