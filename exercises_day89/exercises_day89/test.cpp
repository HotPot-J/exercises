#define _CRT_SECURE_NO_WARNINGS 1

/*
һ��ţţ��������������Ϊһ��������һ�������������У���������������Ƿǵ�������
�ǵݼ�����ġ�ţţ��һ������Ϊn����������A����������һ�������ǰ�����A�ֳ����ɶ�
���������У�ţţ��֪�������ٿ��԰���������Ϊ�������������С�
����ţţ���԰�A��1 2 3 2 2 1������Ϊ1 2 3 �� 2 2 1�������������У�������Ҫ��������������
�������2

����������
	����ĵ�һ��Ϊһ��������n��1<=n<=10^5��
	�ڶ��а���n������ 1~10^9

�������:
	һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
*/

//˼·���ҵ�������ҵݼ�/����ݼ��ҵ���

#include<iostream>
#include<vector>
using namespace std;
void fun( vector<int> arr){
	size_t res = 0, p = 0;
	size_t flag = 0;//��ֵΪ������߲���
	if (arr.size() <= 2){
		//��С����������ʱֻ��һ�����
		cout << 1 << endl;
		return;
	}
	while (p < arr.size() - 1){
		if (arr[p] < arr[p + 1]){
			//����
			while (p<arr.size()-1&&arr[p] <= arr[p + 1]){
				++p;
			}
			++res;
			flag = p; //����
			++p;
		}
		else if (arr[p] == arr[p + 1]){
			++p;
		}
		else {
			//�ݼ�
			while (p < arr.size() - 1 && arr[p] >= arr[p + 1]){
				++p;
			}
			++res;
			flag = p;//����
			++p;
		}
	}
	if (flag != arr.size() - 1){
		++res;
	}
	cout << res;
}
//int main(){
//	vector<int> arr;
//	int n = 0, tmp = 0;
//	cin >> n;
//	for (int i = 0; i < n; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	fun(arr);
//	return 0;
//}

/*
2������һ���ַ���str������ַ���str�е���������ִ�
���� abcd1234ed125ss123456789
�����123456789
*/

//˼·��˫ָ�룬������ͬʱ��������ַ�������
/*substr(pos, length):��string��posλ�ÿ�ʼ��ȡ����Ϊlength���ַ���*/

#include<iostream>
#include<string>
using namespace std;
void fun1(string& str){
	string res;
	int max = 0;
	int tmp = 0;
	size_t front = 0;
	size_t rear = 0;
	size_t tail = 0;
	while (rear < str.size()){
		while (rear<str.size() && !isdigit(str[rear])){
			//�����������
			++rear;
		}
		front = rear;
		while (rear < str.size() && isdigit(str[rear])){
		  //���ҵ��ö����ֵ�ĩβλ��
			++tmp;
			++rear;
		}
		if (tmp>max){
			//�������ֶδ��ڵ�ǰ����������ִ� ����̽�ֵı�Ҫ
			 tail = rear - 1; //�����ֶε�ĩβ
			
			//��ʱ��Ŀת��ΪѰ����������ַ��� ���û������ڽ������
			rear = front;
			tmp = 0; //��¼���ڳ���
			while (rear <= tail){
				if (str[rear + 1] - str[rear] == 1){
					//����
					++tmp;//��¼��ǰ���ڳ���
					++rear;
				}
				else{
					//������
					if (tmp>max){
						res = str.substr(front, tmp+1);
						max = tmp;
						tmp = 0;
					}
					++rear;
					front = rear;
				}
			}
			rear = tail + 1;//������һ�����ֺ� ����������һ��
		}
	}
	cout << res << endl;
}
//int main(){
//	string str;
//	getline(cin, str);
//	fun1(str);
//	return 0;
//}

/*
3�������г��ִ�������һ�������
*/
/*
˼·1����ϣ�� ʱ�临�Ӷ�O��2n��
*/

#include<iostream>
#include<unordered_map>
#include<vector>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		unordered_map<int, int> map;
		int tmp = 0;
		for (int i = 0; i < numbers.size(); ++i){
			tmp = ++map[numbers[i]];
			if (tmp>numbers.size()/2){
				return numbers[i];
			}
		}
		return 0;
	}
};

//˼·2������Ѱ��
#include<iostream>
#include<vector>
#include<algorithm>

//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		if ( numbers.empty()){
//			return 0;
//		}
//		sort(numbers.begin(), numbers.end());
//		int tmp = 1, i = 0, j = 1, res = 0;
//		while (j < numbers.size()){
//			while (numbers[i] == numbers[j]){
//				++j;
//				++tmp;
//			}
//			if (tmp>numbers.size() / 2){
//				return numbers[i];
//			}
//			tmp = 1;
//			i = j;
//			++j;
//		}
//		return 0;
//	}
//};
int main(){
	Solution a;
	vector<int> arr = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	a.MoreThanHalfNum_Solution(arr);
	return 0;
}

