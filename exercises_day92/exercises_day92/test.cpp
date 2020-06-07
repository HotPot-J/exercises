#define _CRT_SECURE_NO_WARNINGS 1

/*
1������С����һ��W*H��������ӣ�������б��Ϊ0~H-1���б��Ϊ0~W-1.ÿ������������Է�
һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2.���������������꣨x1��y1������x2��y2����
ŷ����þ���Ϊ ((x1-x2)^2+(y1-y2)^2))������ƽ���� 
С����֪�������ԷŶ��ٿ鵰�������������
��������:
	ÿ������������񳤿�W H���ÿո�ָ���1<=w,H<=1000��
���������
	��������Էŵĵ�����
����:
	���룺3 2
	�����4
*/
//˼·1:�ݹ����� ̽��ÿһ��λ�õĿ����� Ѱ�����ֵ���÷���ʱ�临�Ӷȸ� �޷�a ����Ϊ���͵Ļ���˼�� ֵ��ѧϰ��

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> coordinate; //�������ŵ�ǰ����ĵ�������� �����ж���һ��λ��
int row = 0;
int res1 = 0;//��ŵ�ǰ·����󵰸���
bool check(int x,int y){
	//�ж��Ƿ���Ϸŵ�������� 
	if (!coordinate.empty()){
		for (size_t i = 0; i < coordinate.size(); ++i){
			if (x == coordinate[i][0] && y == coordinate[i][1]){
				//��λ���Ѿ������ϵ���
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
		//�����߽� ��·���ߵ�ͷ��
		return;
	}
	if (check(x, y)){
		++res1;
		coordinate.resize(row + 1);
		coordinate[row].push_back(x);
		coordinate[row].push_back(y);
		++row;
		dfs(w, h, x, y + 1); //����Ѱ��
		dfs(w, h, x + 1, y);//����Ѱ��
	}
}

//˼·��������һ���СΪh w�Ķ�ά���� ��0��0��ÿ�η�һ������Ͱ�����Χ���ܷŵ�λ��0����

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
2����һ���ַ���ת����һ������(ʵ��integer.valueOf(string)�Ĺ��ܣ�����string������
����Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯������ֵΪ0�����ַ�������һ���Ϸ�
����ֵ�򷵻�0��
��������:
	����һ���ַ���������������ĸ���ţ�����Ϊ��
�������:
	����ǺϷ�����ֵ����򷵻ظ����֣����򷵻�0
���룺+2147483647
		la33
�����2147483647
		0
*/

//˼·�����������ż��� ���з��������ֱ�ӷ���0
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

