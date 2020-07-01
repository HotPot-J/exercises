#define _CRT_SECURE_NO_WARNINGS 1


/*
1、不用加减乘除做加法
*/

/*
思路:位运算  两数异或后:各位置表示产生进位以后的结果 用a表示
			 
			 两数相与后:各位值1代表产生了进位，0代表未产生进位
			 此时将相与后的结果左移一位，该结果用b表示 问题转化a+b
			 
			 当两数相与后为0 说明各个位置均为产生进位 答案即为异或后的结果
	综上，递归解决即可
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
2、三角形
给定三条边，请你判断一下能不能组成一个三角形
*/

/*
思路：条件判断 任意两边之和大于第三边
double的范围是10^-308到10^308
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