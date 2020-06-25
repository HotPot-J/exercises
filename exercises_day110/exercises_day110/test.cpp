#define _CRT_SECURE_NO_WARNINGS 1

/*
1、小易经常沉迷于网络游戏。有一次他在玩一个打怪升级的游戏，他的角色初始能力值为a，在
接下来的一段时间内，他将会遇见n个怪物，每个怪物的防御力为b1，b2，b3...bn.如果遇到的怪
物防御力bi小于等于小易的当前能力值c，那么他就能轻松打败怪物，并且使自己的能力值增加bi；
如果bi大于c，那么他也能打败怪物，但他的能力只能增加bi与c的最大公约数。那么问题来了，在
一系列的锻炼后，小易的最终能力值为多少？
输入描述：
	对于每组数据，第一行是两个整数n(1<=n<100000)表示怪物的数量和a表示小易的初始能力值
	第二行n个整数，b1，b2...bn(1<=bi<=n)表示每个怪物的防御力
输出描述:
	对于每组数据，输出一行，每行仅包含一个整数，表示小易的最终能力值
输入:
	3 50
    50 105 200
输出:
	110
*/
/*
思路:辗转相除求最大公约数
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//最大公约数
int func(int _max, int _min){
	if (_max%_min == 0){
		return _min;
	}
	return func(_min, _max%_min);
}

//int main(){
//	int n = 0, a = 0;
//	while (cin >> n >> a){
//		vector<int> arr;
//		int tmp = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> tmp;
//			arr.push_back(tmp);
//		}
//		for (int i = 0; i < n; ++i){
//			if (arr[i] <= a){
//				a += arr[i];
//			}
//			else{
//				a += func(max(a, arr[i]), min(a, arr[i]));
//			}
//		}
//		cout << a << endl;
//	}
//	return 0;
//}

/*
2、找出字符串中第一个只出现一次的字符
输入：输入一个非空字符串
输出：输出一个人只出现一次的字符，如果不存在输出-1
*/

/*
思路:哈希 
*/
#include<iostream>
#include<map>
#include<string>
using namespace std;

//int main(){
//	map<char, int> _map;
//	string str;
//	while (getline(cin, str)){
//		for (auto a : str){
//			_map[a]++;
//		}
//		map<char, bool> map2;
//		map<char, int>::iterator it = _map.begin();
//		while (it != _map.end()){
//			if (it->second==1){
//				map2.insert(make_pair(it->first, true));
//			}
//			++it;
//		}
//		int flag = 1;
//		for (auto a : str){
//			if (map2[a]){
//				flag = 0;
//				cout << a << endl;
//				break;
//			}
//		}
//		if (flag){
//			cout << -1 << endl;
//		}
//	}
//	return 0;
//}

/*
思路2：从左往右找当前字符，从右往左找当前字符，若返回同一下标 则说明只有一个该字符
*/

int main(){
	string str;
	while (getline(cin, str)){
		int len = str.size();
		int i = 0;
		for ( i = 0; i < len; ++i){
			if (str.find(str[i]) == str.rfind(str[i])){
				cout << str[i] << endl;
				break;
			}
		}
		if (i == len){
			cout << -1 << endl;
		}
	}
	return 0;
}