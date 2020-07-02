#define _CRT_SECURE_NO_WARNINGS 1

/*
1、奇数位上的都是奇数，偶数位上的都是偶数
在给定一个长度不小于2的数值arr。写一个函数调整arr，使得arr中要么所有奇数位上都是奇数，
要么所有偶数位上都是偶数。时间复杂度位O（N） 空间复杂度O（1） 下标0，2，4位偶位，1 3 7
为奇数位，例如[1 2 3 4]调整成 [2 1 4 3]即可
*/

/*
思路： 双指针  一个永远指向奇数位odd 一个永远指向偶数位 even
1.若odd指向的数字为偶，even指向的为奇，直接互换
2.若odd指向偶，even为偶，则even符合条件 指向下一个偶数位 add不动
3.若odd指向奇，even指向奇，则odd符合条件 指向下一个奇数位 even不动
4.符合条件，双指针均向后遍历
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int even = 0, odd = 1;
		while (even < len&&odd < len){
			//情况1：
			if (arr[even] % 2 != 0 && arr[odd] % 2 == 0){
				swap(arr[even], arr[odd]);
				even += 2;
				odd += 2;
			}
			//情况2：
			else if (arr[even] % 2 == 0 && arr[odd] % 2 == 0){
				even += 2;
			}
			//情况3：
			else if (arr[even] % 2 != 0 && arr[odd] % 2 != 0){
				odd += 2;
			}
			//情况4：
			else{
				even += 2;
				odd += 2;
			}
		}
	}
};

//int main(){
//	vector<int> a = { 7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6 };
//	Solution b;
//	b.oddInOddEvenInEven(a, 4);
//	return 0;
//}

/*
2、猴子分桃 牛客
*/

/*
思路： n只小猴子 设最初有m个桃子  由于给猴子分配每次都会多出来一个 则m+4正好被5整除
第一个小猴子拿的加上老猴子的那一个正好 = （m+4）*(1/5)  剩余 （m+4）*（4/5）
第二个小猴子拿走1/5后 剩余（m-4）*（4/5）^2
...
第n个小猴子拿走1/5后  剩余（m-4）*（4/5）^n
由于(m-4)*（4/5）^n 可以被5整除 所以该结果为整数恒成立 则（m-4） = 5^n恒成立
	那么 m = 5^n-4恒成立
	老猴子最终可获得:（m-4）*（4/5）^n + n -4 = 4^n+n-4 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			break;
		}
		long m = pow(double(5), double(n)) - 4;
		long oldM = pow(double(4), double(n)) + n - 4;
		cout << m << " " << oldM << endl;
	}
	return 0;
}