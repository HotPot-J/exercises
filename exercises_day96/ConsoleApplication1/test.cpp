#define _CRT_SECURE_NO_WARNINGS 1

/*
1��������
����һ�������ľ��������̣������һ����Ч�㷨�жϵ�ǰ����Ƿ��ʤ��
����һ����ά����board������ǰ���̣�����Ԫ��Ϊ1�Ĵ����ǵ�ǰ��ҵ����ӣ�Ϊ0
��ʾû�����ӣ�Ϊ-1�����ǶԷ���ҵ�����
����
	{[1,0,1],[1,-1,-1],[1,-1,0]}
���أ�true
*/

//˼·�������� �޷Ǿ�8�ֻ�ʤ�Ŀ�����3��3�� ���Խ��� ֱ���жϼ���
#include<iostream>
#include<vector>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int>> board) {
		//��б
		if (board[0][0] + board[1][1] + board[2][2] == 3) return true;
		if (board[0][2] + board[1][1] + board[2][0] == 3) return true;
		for (int i = 0; i<3; i++){
			//����
			if (board[i][0] + board[i][1] + board[i][2] == 3) return true;
			//����
			if (board[0][i] + board[1][i] + board[2][i] == 3) return true;
		}
		return false;
	}
};

/*
2������ǿ�ȵȼ�
���밴���¹�����мƷ֣������ݲ�ͬ�ĵ÷�Ϊ������а�ȫ�ȼ�����
һ�����볤�ȣ�
5�֣�<=4
10��:5~7
25:>=8

������ĸ��
0������ĸ
10��ȫ�ǣ���/��С��д��ĸ
20����С���

��������
0��û����
10��1������
20������һ������

�ġ����ţ�
0���޷���
10��1������
25������һ������

�塢
������
2����ĸ������
3����ĸ���ַ���
5:��Сд��ĸ�����ֺͷ���

���ֱ�׼:
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
	//����
	int res = 0;

	//��������
	if (len < 5){
		res += 5;
	}
	else if (len <= 7){
		res += 10;
	}
	else{
		res += 25;
	}

	//��������
	if (num == 1){
		res += 10;
	}
	else if (num > 1){
		res += 20;
	}

	//��������
	if (_char == 1){
		res += 10;
	}
	else if (_char > 1){
		res += 25;
	}

	//��ĸ����
	if (anum&&Anum){
		//���
		res += 20;
	}
	else if (anum || Anum){
		res += 10;
	}

	//��������
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
	//ͳ�Ƹ���ָ�����
	int len = 0, Anum = 0, anum = 0, num = 0, _char = 0;
	len = s.size();
	for (int i = 0; i < len; ++i){
		if (isalnum(s[i])){
			//�ж��������ֻ�����ĸ
			if (isalpha(s[i])){
				//�ж�������ĸ
				if (islower(s[i])){
					//�ж���ΪСд
					++anum;
				}
				else{
					++Anum;
				}
			}
			else{
				//Ϊ����
				++num;
			}
		}
		else{
			//Ϊ�ַ�
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

