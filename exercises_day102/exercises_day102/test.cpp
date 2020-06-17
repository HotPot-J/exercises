#define _CRT_SECURE_NO_WARNINGS 1

/*
1、查找输入整数二进制中1的个数
请实现如下接口：
	public static int findNumberOf1(int num)
	{
		
	}
输入描述:
	输入一个整数 5
输出描述：
	计算整数二进制中1的个数 2

*/

//思路：位运算
#include<iostream>
using namespace std;

int findNumberOf1(int num)
{
	int res = 0;
	for (int i = 0; i < 32; ++i){
		if ((num >> i)&1){
			++res;
		}
	}
	return res;
}
//int main(){
//	int num = 0;
//	while (cin >> num){
//		cout << findNumberOf1(num) << endl;
//	}
//	return 0;
//}

/*
2.手套
	地下室放着n中颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定
	相同,A先生现在要出门，所以他会多拿一些手套，然后选出一双颜色相同的左右手
	手套。现在的问题是，他至少要拿多少只手套左手(左手+右手)，才能保证一定能
	选出一双颜色相同的手套。
	给定颜色种数n(1<=n<=13)，同时给定两个长度为n的数组，left，right，分别代表
	每种颜色左右手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种
	合法方案。
测试样例:
	4,[0,7,1,6] [1,5,0,6]
返回：10(解释：可以左手手套取两只，右手手套取8只)
*/

/*
思路： 该题的确未理解题意 参考了网上大佬的思路：
	有一段长度为n的有序序列：2 4 6 9  选择一个多大的数字能够保证在其中
	任选n-1个数的和都小于所选数字呢？自然是选择最大的三个数之和
	如何覆盖住整个数组呢？
	自然是选择最大的三个数之和再+1 即（2+4+6+9）-2+1 （即选了n-1个数，再多选一个，就能选到没被剩下的那个数的一个单位）
	可推得：最小覆盖数 = sum(arr)-arr[min]+1

此题即为：找到left的最小覆盖数 找到right的最小覆盖数 再选其最小的覆盖数+1即为结果
当有一边颜色为0一边手套不为0的情况，则需要将残缺手套全拿走才能保证题意
*/

#include<vector>

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int res = 0;
		int sum_left = 0;
		int sum_right = 0;
		//有序颜色和个数一一对应 无法直接排序选出最小值 这里定义min将最小值筛选出来
		int left_min = INT_MAX;
		int right_min = INT_MAX;
		for (int i = 0; i < n; ++i){
			if (left[i] && right[i]){
				//求和（不包含一方有该颜色手套，一方无该色手套）
				sum_left += left[i];
				sum_right += right[i];
				//筛选最小值
				left_min = left_min>left[i] ? left[i] : left_min;
				right_min = right_min > right[i] ? right[i] : right_min;
			}
			else{
				//当其中一方为0
				res += (left[i] + right[i]);
			}
		}
		int L = sum_left - left_min + 1;
		int R = sum_right - right_min + 1;
		int lr_min = L < R ? L : R;
		return  res + lr_min + 1;
	}
};
//int main(){
//	vector<int> l = { 0, 7, 1, 6 };
//	vector<int> r = { 1, 5, 0, 6 };
//	Gloves a;
//	a.findMinimum(4, l, r);
//	return 0;
//}