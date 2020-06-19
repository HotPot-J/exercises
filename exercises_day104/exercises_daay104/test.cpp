#define _CRT_SECURE_NO_WARNINGS 1

/*
1、杨辉三角的变形

以上三角形矩阵，第一行只有一个数1，以下的每行的每个数，恰好是它上面的数，左上角到右上角的数，三个数之和
(如果不存在某个数，认为该数为0)
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1.例如输入3，则输出2，输入4则输出3
*/

/*
思路:通过画图寻找规律：
	当n<3 即前两行均为1，不符合条件输出-1 
	
	n为奇数 第一个偶数在第二位
	
	n为偶数且能被4整除 在第三位
			 不能被4整除在第四位
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
//			//奇数
//			cout << 2 << endl;
//		}
//		else{
//			//偶数
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
2、请设计一个算法完成两个超长正整数加法
接口说明:
	输入参数：
		string addend：加数
		string augend：被加数
	返回值：加法结果
*/

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		int flag = 0;//初始化进制位为0
		int ret = 0;
		string addret;
		int i = num1.size() - 1, j = num2.size() - 1;
		int size1 = i + 1, size2 = j + 1;
		while (size1&&size2){
			ret = (((num1[i] - '0') + (num2[j] - '0') + flag) % 10);
			addret += (ret + '0');
			//addret.insert(addret.begin(), ret+'0');//头插进去 就不用翻转了
			flag = (((num1[i--] - '0') + (num2[j--] - '0') + flag) / 10);
			size1--;
			size2--;
		}
		while (size1){
			//当num1还有剩余高位数
			ret = (((num1[i] - '0') + flag) % 10);
			addret += (ret + '0');
			//addret.insert(addret.begin(), ret + '0');
			flag = (((num1[i--] - '0') + flag) / 10);
			size1--;
		}
		while (size2){
			//当num2还有剩余高位数
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
