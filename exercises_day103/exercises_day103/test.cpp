#define _CRT_SECURE_NO_WARNINGS 1

/*
1.iNOC产品部--完全数计算
完全数，又称完美数或完备数，是一些特殊的自然数。
他所有真因子(除了自身意外的约数)的和,恰好等于他本身。
例如：28  约数：1 2 4 7 14 28 ，出去它本身28以外，其余5个数相加，
1+2+4+7+14 = 28 
给定函数count(int n)，用于计算n以内(含n)完全数的个数。计算范围，0<n<=5000000
返回n以内完全数的个数，异常返回-1
输入一个数字
输出完全数的个数
*/

/*
思路：暴力法
*/
#include<iostream>
#include<vector>
using namespace std;
//int main(){
//	int n = 0;
//	while (cin >> n){
//		int res = 0;
//		for (int i = 4; i <= n; ++i){
//			vector<int> arr;
//			for (int j = 1; j < i; ++j){
//				if (i%j == 0){
//					arr.push_back(j);
//				}
//			}
//			int sum = 0;
//			for (size_t k = 0; k < arr.size(); ++k){
//				sum += arr[k];
//			}
//			if (sum == i){
//				++res;
//			}
//		}
//		cout << res << endl;
//	}
//	return 0;
//}


/*
扑克牌游戏，一副牌由54张组成，3~A 、2各四张，大小王各一张，牌面从小到大用如下
字符和字符串表示(其中，小写joker表示小王，JOKER表示大王)：
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两张手牌，两手牌之间用“-”连接
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
基本规则:
	1.输入每手牌可能是个子、对子、顺子(连续5张)、三个、炸弹(四个)和对王中的
	一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列
	2.除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较
	关系(如，对子跟对子比较、三个跟三个比较)，不考虑拆牌的情况(如：将对子拆分为个子)
	3.大小规则和平时了解的常见规则相同，个子、对子、三个比较牌面大小，顺子比较
	最小牌大小；炸弹大于前面面所有的牌，炸弹之间比较牌面大小，对王是最大的牌
	4.输入的两手牌不会出现相等的情况
输入描述:
	输入两手牌，两手牌之间用"-"连接，每手牌的每张以空格分隔，"-"两边没有空格
	如：4 4 4 4-joker JOKER
输出描述：
		输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍然以空格隔开；
		如果不存在比较关系则输出ERROR
例子:
输入:	4 4 4 4-joker JOKER
输出:	joker JOKER
*/

/*
思路：字符串匹配问题   将所有牌面存进map中<key,value> value越大牌面越大 
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
void _size(string& s,int& size){
	int tmp = 0;
	if (s=="joker"){
		tmp = -1;
	}
	else if(s == "JOKER"){
		tmp = 0;
	}
	else if (s == "joker JOKER"){
		tmp = 6;
	}
	else{
		for (size_t i = 0; i < s.size(); ++i){
			if (s[i] != ' '){
				//检查其有无10  10在内存中的存储为‘1’‘0’多占一个字节
				if ((i+1<s.size())&&s[i] == '1' && s[i + 1] == '0'){
					++i;
				}
				++tmp;
			}
		}
	}
	size = tmp;
}
int main(){
	string s;
	//建立牌面大小关系 
	vector<string> arr = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "joker" };
	map<string, int> map;
	for (size_t i = 0; i < arr.size(); ++i){
		map[arr[i]] = i;
	}

	while (getline(cin, s)){
		//寻找"-"在字符串的位置
		size_t pos = s.find("-");

		//分离出两对牌
		string left = s.substr(0, pos);
		string right = s.substr(pos + 1, s.size() - pos);
		
		//判断牌的种类：个子/对子....
		int leftSize = 0, rightSize = 0;
		_size(left, leftSize);
		_size(right, rightSize);
	
		//相同类型的牌比较
		if (leftSize == rightSize){
			//如果两手牌fun返回值相等
			//则为个子/对子/三个/炸弹只需要比较其第一个字符即可
			//(这种情况个子之间的比较不包括个子和王之间的比较)
			string L(1, left[0]);
			string R(1, right[0]);
			if (leftSize >= 2){
				if (left[0] == '1'&&left[1] == '0'){
					L.clear();
					L = "10";
				}
				if (right[0] == '1'&&right[1] == '0'){
					R.clear();
					R = "10";
				}
			}
				if (map[L] > map[R]){
					cout << left << endl;
					continue;
				}
				 if(map[L]<map[R]){
					cout << right << endl;
					continue;
				}
		}
		else{
			if ((leftSize == -1 && rightSize == 0) || (leftSize == 0 && rightSize == -1)){
				//两个大王之间的比较
				cout << "JOKER" << endl;
				continue;
			}
			if (leftSize == 1 || rightSize == 1){
				//单张和王之间的比较
				if (leftSize == -1||rightSize==-1){
					cout << "joker" << endl;
					continue;
				}
				else if (leftSize == 0 || rightSize == 0){
					cout << "JOKER" << endl;
					continue;
				}
			}
			//不同类型的牌比较
			 if (leftSize == 6 || rightSize == 6){
				//只要有一方为王炸直接输出王炸
				cout << "joker JOKER" << endl;
				continue;
			}
			//不同类型下 排除王炸 只有炸弹最大 
			 if (leftSize == 4){
				cout << left << endl;
				continue;
			}
			 if (rightSize == 4){
				 cout << right << endl;
				 continue;
			 }
		}
		cout << "ERROR" << endl;
	}
	return 0;
}

