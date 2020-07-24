#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

/*
1、合唱团
有n个同学站成一排，每个学生有一个能力值，牛牛想从这n个学生中按照顺序选取K名同学，要求
相邻两个学生的位置编号的差不超过d，使得这K个学生的能力值的乘积最大，你能返回最大的乘积
吗？
输入描述:
	每个输入包含1个测试用例。每个测试数据的第一行包含一个整数n(1<=n<=50)，表示学生的个数
	接下来的一行，包含n个整数，按照顺序表示每个学生的能力值ai(-50<=ai<=50)。接下来的一行
	包含两个整数，k和d(1<=k<=10,1<=d<=50)
输出描述：
	输出一行表示最大的乘积

例子:
	输入：
		3
		7 4 7
		2 50
	输出：
		49
*/

/*
思路：动态规划:
   （ps：本题参考了其他大佬的做法受益匪浅--、）
   由于本题的各种线性要求，而动态规划要求从上一状态，
   推测出下一状态的最优解我们采用如下推导过程：
	1.我们选择第i个位置，作为第k个数字的固定位置，那么剩下的k-1个数字在i位置之前的
	位置寻找
	
	2.我们假设j为第k-1个数字，题目要求相邻数字坐标不能超过d，那么j必须满足 
	i-j<=d&&j>0 (我们让所有下标从1开始，便于dp数组的规划)
	
	3.我们一共要寻找k个数字的乘积组合，所以设dp[k+1][n+1]
	
	4.由于该题为乘积，且包含有负数，那么我们需要维护两个dp：dp_max和dp_min，因为
	在遇到负数时，max = min*负数

	5.递推公式见源代码 DynamicProgramming函数（根据下标比较便于理解该公式）

	6.以后一时无法理解，记得画个表格，走一遍代码就明白了--、
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void DynamicProgramming(vector<long long>& arr,int& n ,int& K,int& d){

	//定义保存最大值
	long long res = LONG_MIN;
	//首先我们定义并初始化两个dp二维数组
	vector<vector<long long>> dp_max;
	vector<vector<long long>> dp_min;
	dp_max.resize(K + 1); dp_min.resize(K + 1);
	for (int i = 0; i < K + 1; ++i){
		dp_max[i].resize(n + 1, 0);
		dp_min[i].resize(n + 1, 0);
	}
	//接下来进行迭代过程
	//dp_max[k][i] = max(dp_max[k][i],dp_max[k-1][j]*arr[i],dp_min[k-1][j]*arr[i])
	//dp_max[k][i] = min(dp_min[k][i],dp_max[k-1][j]*arr[i],dp_min[k-1][j]*arr[i])
	// k代表行，即第几个数字    j代表列，即第k-1个数字的位置    i即确定的第k个数字位置
	for (int i = 1; i <= n; ++i){
		//为dp[1][i]第一行第i列赋值，以固定第k个数字
		dp_max[1][i] = arr[i];
		dp_min[1][i] = arr[i];
		//控制结果为K个数字相乘的最大值
		for (int k = 2; k <= K; ++k){
			//这是第k-1个数字的位置，自然从i-1开始（第一个已经固定）
			for (int j = i - 1; j > 0 && i - j <= d; --j){
				dp_max[k][i] = max(dp_max[k][i], max(dp_max[k - 1][j] * arr[i], dp_min[k - 1][j] * arr[i]));
				dp_min[k][i] = min(dp_min[k][i], min(dp_max[k - 1][j] * arr[i], dp_min[k - 1][j] * arr[i]));
			}
		}
		//当第二层for循环结束，就会得到一个当前k个数相乘的最大值
		res = max(dp_max[K][i] , res);
	}
	cout << res << endl;
}

//int main(){
//	int n = 0;
//	while (cin >> n){
//		vector<long long> students;
//		int tmp = 0;
//		//让有效数字的下标从1开始，便于后期的处理
//		students.push_back(0);
//		for (int i = 1; i <= n; ++i){
//			cin >> tmp;
//			students.push_back(tmp);
//		}
//		int k = 0, d = 0;
//		cin >> k >> d;
//		 DynamicProgramming(students,n,k,d) ;
//	}
//	return 0;
//}


/*
1、马戏团
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后
发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到，马戏团正打算出一个新节目"最
高罗汉塔"，即马戏团叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人
应该比自己矮和瘦，或相等。团长想要本次的罗汉塔叠的的最高，由于人数众多，正在头疼如何
安排人员。小王觉得很简单，于是统计了参与演员的身高体重，并且很快找到叠最高罗汉的高度，
这份表中马戏团员依次编号为1-N。

输入描述:
	首先一个正整数N，表示人员个数
输出描述:
	正整数m，表示罗汉塔的高度
*/

/*
思路:
	1.比自己高的必定不能站在自己肩膀上，所以按照身高降序排列（由高到低）
	（sort即可解决）
	2.然后身高从左至右必定满足条件，那么我们只需要找出按照体重的最长递减序列即可
	（动态规划） dp[i] = max(dp[j])+1 j<i且num[i]<num[j]

*/

#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
struct man
{
	int _w;
	int _h;
};
bool cmp(man& a, man& b){
	//降序
	if (a._h == b._h){
		//体重相等的情况下 重的在前面
		return a._w > b._w;
	}
	return a._h > b._h;
}
int main(){
	int n = 0;
	while (cin >> n){
		int index = 0, w = 0, h = 0;
		vector<man> arr;
		for (int i = 0; i < n; ++i){
			man tmp;
			cin >> index >> w >> h;
			tmp._w = w;
			tmp._h = h;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end(), cmp);

		//寻找arr的长体重递减序列
		vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i){
			dp[i] = 1;
			for (int j = 0; j < i; ++j){
				//体重相等且身高相等才能叠
				if ((arr[j]._w>arr[i]._w)||
					(arr[j]._w == arr[i]._w&&arr[j]._h==arr[i]._h)
					){
					dp[i] = max(dp[i], dp[j] + 1);
				}
				
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i){
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
	return 0;
}