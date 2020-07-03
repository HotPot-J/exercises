#define _CRT_SECURE_NO_WARNINGS 1

/*
1、求正整数数组的最小不可组成和 （牛客）
*/

/*
思路:对arr排序 求出min和max   核心其实是求[min，max]区间中最小不能被arr中相加得到的数字
 用dfs+回溯法+剪枝+设置搜索起点去重 去寻找可能解
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	/**
	*	正数数组中的最小不可组成和
	*	输入：正数数组arr
	*	返回：正数数组中的最小不可组成和
	*/
	bool flag = false;
	void dfs(int begin, int target,vector<int>& arr){
		//begin为本轮搜索的起点下标  (由于是子集，不允许出现相同数字，下一轮搜索起点为上一轮起点+1)
		if (target == 0){
			//找到可行解
			flag = true;
			return;
		}
		for (size_t i = begin; i < arr.size(); ++i){
			if (target - arr[i] < 0){
				//不符合条件 "剪枝" 后边的数字也不用判断了 退出循环进行回溯
				break;
			}
			target -= arr[i];
			dfs(i+1, target, arr);
			target += arr[i];
		}
	}
	int getFirstUnFormedNum(vector<int> arr, int len) {
		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = 0;
		for (int i = 0; i < len; ++i){
			max += arr[i];
		}
		for (int i = min; i <= max; ++i){
			flag = false;
			dfs(0,i,arr);
			if (flag == false){
				return i;
			}
		}
		return max + 1;
	}
};

//int main(){
//	Solution a;
//	vector<int> arr = { 3,2,5 };
// 	a.getFirstUnFormedNum(arr,3);
//	return 0;
//}

/*
2、有假币 （牛客）

居然有假币！现在猪肉涨了，但是农名工的工资不见涨，没钱怎么买猪肉?nowcoder这就去买猪肉，
结果找来的零钱中有假币。可惜nowcoder一不小心把它混进真币里面了。只知道假币比真币轻，
给你一个天平(天平两端能容纳无限硬币)，请用最快的时间找出假币。
输入：
	1<=n<=2^30，输入0结束
输出:
	最多要称几次一定能找出假币？
*/

/*
思路：枚举一部分找规律
	1--》0
	2--》1
	3： 分为 1 1 1 三堆 只需要称一次就能定性：平则剩为假  不平则高为假
	4：分为 1 1 2三堆  考虑最坏情况：1 1平衡 则2需要再称一次 总共2次
	5：分为 2  2 1三堆  最坏情况 分别称两个2都相等 则一定在剩下的哪个 所以称2次

	可以推出 分为三份以后 多的那一堆继续去称 直到n==1 返回0次 n<=3返回一次
	
*/
#include<iostream>
using namespace std;

int func(int n){
	if (n <= 1){
		return 0;
	}
	if (n <= 3){
		return 1;
	}
	//（n+0）/3 == (n+1)/3==(n+2)/3 当n%3余0余1余2,大的那一堆 = （n/3+n%3）/3 = （n+2）/3
	return func((2 + n) / 3) + 1;
}
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			break;
		}
		cout << func(n) << endl;
	}
	return 0;
}