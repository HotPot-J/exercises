#define _CRT_SECURE_NO_WARNINGS 1

/*
1、二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，列编号为0~W-1.每个格子至多可以放
一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2.对于两个格子坐标（x1，y1），（x2，y2）的
欧几里得距离为 ((x1-x2)^2+(y1-y2)^2))的算数平方根 
小易想知道最多可以放多少块蛋糕在网格盒子里
输入描述:
	每组数组包含网格长宽W H，用空格分隔（1<=w,H<=1000）
输出描述：
	输出最多可以放的蛋糕数
例子:
	输入：3 2
	输出：4
*/
//思路1:递归搜索 探索每一个位置的可能性 寻找最大值（该方法时间复杂度高 无法a 但是为典型的回溯思想 值得学习）

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> coordinate; //该数组存放当前放入的蛋糕的坐标 用来判断下一个位置
int row = 0;
int res1 = 0;//存放当前路径最大蛋糕数
bool check(int x,int y){
	//判断是否符合放蛋糕的条件 
	if (!coordinate.empty()){
		for (size_t i = 0; i < coordinate.size(); ++i){
			if (x == coordinate[i][0] && y == coordinate[i][1]){
				//该位置已经被放上蛋糕
				return false;
			}
			int a = (x - coordinate[i][0])*(x - coordinate[i][0]);
			int b = (y - coordinate[i][1])*(y - coordinate[i][1]);
			if (a + b == 4){
				return false;
			}
		}
	}
	return true;
}
void dfs(int w,int h,int x,int y ){
	if (x >= w || y >= h){
		//超出边界 该路径走到头了
		return;
	}
	if (check(x, y)){
		++res1;
		coordinate.resize(row + 1);
		coordinate[row].push_back(x);
		coordinate[row].push_back(y);
		++row;
		dfs(w, h, x, y + 1); //向右寻找
		dfs(w, h, x + 1, y);//向下寻找
	}
}

//思路二：遍历一遍大小为h w的二维数组 从0，0起，每次放一个蛋糕就把其周围不能放的位置0即可

#include<iostream>
#include<vector>

using namespace std;
void can_push(vector<vector<int>>& vv, int row, int clow) {
	if (row + 2 < vv.size() && vv[row][clow] > 0) {
		vv[row + 2][clow] = -1;
	}
	if (clow + 2 < vv[row].size() && vv[row][clow] > 0) {
		vv[row][clow + 2] = -1;
	}
}
int main() {
	vector<vector<int>> vv;
	int W, H;
	int i = 0;
	int count = 0;
	cin >> W >> H;
	int row = W;
	int clow = H;
	vv.resize(W);
	while (row--) {
		vv[i].resize(H, 0);
		i++;
	}
	i = 0;
	int j = 0;
	for (i = 0; i < W; i++) {
		for (j = 0; j < H; j++) {
			if (vv[i][j] == 0) {
				++count;
				vv[i][j] = count;
				can_push(vv, i, j);
			}
		}
	}
	cout << count << endl;
}

/*
2、讲一个字符串转换成一个整数(实现integer.valueOf(string)的功能，但是string不符合
数字要求时返回0)，要求不能使用字符串转换整数的库函数。数值为0或者字符串不是一个合法
的数值则返回0；
输入描述:
	输入一个字符串，包括数字字母符号，可以为空
输出描述:
	如果是合法的数值表达则返回该数字，否则返回0
输入：+2147483647
		la33
输出：2147483647
		0
*/

//思路：保留正负号即可 当有非数组出现直接返回0
class Solution {
public:
	int StrToInt(string str) {
		int result = 0;
		if (str.size() <= 0){
			return 0;
		}
		int i = 0;
		int flag = 0;
		if (str[i] == ' ')
		{
			i++;
		}
		if (str[i] == '+')
		{
			flag = 1;
			i++;
		}
		else if (str[i] == '-')
		{
			flag = -1;
			i++;
		}
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				result = result * 10 + (str[i] - '0');
				i++;
			}
			else{
				return 0;

			}
		}
		if (flag == -1){
			result = -result;
		}
		return result;
	}
};

