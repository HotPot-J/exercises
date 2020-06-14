#define _CRT_SECURE_NO_WARNINGS 1

/*
1、二进制插入
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的的二进制的第j到第i位。
其中二进制的位数从低位到高位以0开始。
给定两个数int n和 int m，同时给定int j进而int i，意义如题所述，请返回操作后的数
保证n的第j到第i为均为0，且m的二进制位数小于i-j+1
样例：
	1024，19，2，6
	返回：1100
*/

/*思路 位运算 让m左移j位和n进行|运算即可
1024：	100 0000 0000   19：1 0011
             100 11			  
*/
#include<iostream>
using namespace std;
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		n |= m;
		return n;
	}
};

//int main(){
//	BinInsert a;
//	cout<<a.binInsert(1024, 19, 2, 6)<<endl;
//	return 0;
//}

/*
2、查找组成一个偶数最接近的两个素数
任何一个偶数(大于2)，都可以由两个素数组成，组成偶数的2个素数有很多种情况，本题目要求
输出组成指定偶数的两个素数差值最小的素数对。
输入：一个偶数  20

输出：两个素数 7
			   13
*/

/*
思路: 根据题意，将偶数除以二，同时同步从左和从右去寻找 ，当左右均为素数 则满足题意
*/

#include<iostream>
using namespace std;
bool fun(int x){
	int tmp = x / 2;
	for (int i = 2; i <= tmp; ++i){
		if (x%i == 0){
			return false;
		}
	}
	return true;
}
void find_(int n){
	int mid = n / 2;
	int left = mid, right = mid;
		while (1)
		{
			if (fun(left) && fun(right)){
				break;
			}
			left--;
			right++;
		}
		cout << left << endl;
		cout << right << endl;
		
}

//int main(){
//	int n = 0;
//	while (cin >> n){
//		find_(n);
//	}
//	return 0;
//}

