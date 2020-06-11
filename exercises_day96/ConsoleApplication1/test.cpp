#define _CRT_SECURE_NO_WARNINGS 1

/*
1、井子棋
对于一个给定的井子棋棋盘，请设计一个高效算法判断当前玩家是否获胜。
给定一个二维数组board，代表当前棋盘，其中元素为1的代表是当前玩家的棋子，为0
表示没有棋子，为-1代表是对方玩家的棋子
例：
	{[1,0,1],[1,-1,-1],[1,-1,0]}
返回：true
*/

//思路：暴力法 无非就8种获胜的可能性3横3竖 两对角线 直接判断即可
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		//两斜
		if (board[0][0] + board[1][1] + board[2][2] == 3) return true;
		if (board[0][2] + board[1][1] + board[2][0] == 3) return true;
		for (int i = 0; i<3; i++){
			//三横
			if (board[i][0] + board[i][1] + board[i][2] == 3) return true;
			//三竖
			if (board[0][i] + board[1][i] + board[2][i] == 3) return true;
		}
		return false;
	}
};

/*
2、密码强度等级
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分
一、密码长度：
5分：<=4
10分:5~7
25:>=8

二、字母：
0：无字母
10：全是（大）/（小）写字母
20：大小混合

三、数字
0：没数字
10：1个数字
20：大于一个数字

四、符号：
0：无符号
10：1个符号
25：大于一个符号

五、
奖励：
2：字母和数字
3：字母数字符号
5:大小写字母、数字和符号

评分标准:
	>=90:VERY_WEAK
	>=80:WEAK
	>=70:AVERAGE
	>=60:STRONG
	>=50:VERY_STRONG
	>=25:SECURE
	>=0:VERY_SECURE
*/
#include<iostream>
#include<string>
using namespace std;
void print_(int res){
	if (res >= 90){
		cout << "VERY_SECURE" << endl;
	}
	else if (res >= 80){
		cout << "SECURE" << endl;
	}
	else if (res >= 70){
		cout << "VERY_STRONG" << endl;
	}
	else if (res >= 60){
		cout << "STRONG" << endl;
	}
	else if (res >= 50){
		cout << "AVERAGE" << endl;
	}
	else if (res >= 25){
		cout << "WEAK" << endl;
	}
	else{
		cout << "VVERY_WEAK" << endl;
	}

}
void score(int len,int Anum,int anum,int num,int _char){
	//评分
	int res = 0;

	//长度评分
	if (len < 5){
		res += 5;
	}
	else if (len <= 7){
		res += 10;
	}
	else{
		res += 25;
	}

	//数字评分
	if (num == 1){
		res += 10;
	}
	else if (num > 1){
		res += 20;
	}

	//符号评分
	if (_char == 1){
		res += 10;
	}
	else if (_char > 1){
		res += 25;
	}

	//字母评分
	if (anum&&Anum){
		//混合
		res += 20;
	}
	else if (anum || Anum){
		res += 10;
	}

	//奖励评分
	if (anum&&Anum&&num&&_char){
		res += 5;
	}
	else if ((anum || Anum) && num&&_char){
		res += 3;
	}
	else if((anum||Anum)&&num){
		res += 2;
	}
	print_(res);
}
void count(string s){
	if (s.size() < 1){
		return;
	}
	//统计各项指标个数
	int len = 0, Anum = 0, anum = 0, num = 0, _char = 0;
	len = s.size();
	for (int i = 0; i < len; ++i){
		if (isalnum(s[i])){
			//判断其是数字或者字母
			if (isalpha(s[i])){
				//判断其是字母
				if (islower(s[i])){
					//判断其为小写
					++anum;
				}
				else{
					++Anum;
				}
			}
			else{
				//为数字
				++num;
			}
		}
		else{
			//为字符
			++_char;
		}
	}
	score(len, Anum, anum, num, _char);
}
int main(){
	string s;
	while (getline(cin, s)){
		count(s);
	}
	return 0;
}

