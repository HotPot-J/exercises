#define _CRT_SECURE_NO_WARNINGS 1

/*
1.iNOC��Ʒ��--��ȫ������
��ȫ�����ֳ����������걸������һЩ�������Ȼ����
������������(�������������Լ��)�ĺ�,ǡ�õ���������
���磺28  Լ����1 2 4 7 14 28 ����ȥ������28���⣬����5������ӣ�
1+2+4+7+14 = 28 
��������count(int n)�����ڼ���n����(��n)��ȫ���ĸ��������㷶Χ��0<n<=5000000
����n������ȫ���ĸ������쳣����-1
����һ������
�����ȫ���ĸ���
*/

/*
˼·��������
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
�˿�����Ϸ��һ������54����ɣ�3~A ��2�����ţ���С����һ�ţ������С����������
�ַ����ַ�����ʾ(���У�Сдjoker��ʾС����JOKER��ʾ����)��
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
�����������ƣ�������֮���á�-������
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR��
��������:
	1.����ÿ���ƿ����Ǹ��ӡ����ӡ�˳��(����5��)��������ը��(�ĸ�)�Ͷ����е�
	һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С��������
	2.����ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽ�
	��ϵ(�磬���Ӹ����ӱȽϡ������������Ƚ�)�������ǲ��Ƶ����(�磺�����Ӳ��Ϊ����)
	3.��С�����ƽʱ�˽�ĳ���������ͬ�����ӡ����ӡ������Ƚ������С��˳�ӱȽ�
	��С�ƴ�С��ը������ǰ�������е��ƣ�ը��֮��Ƚ������С��������������
	4.����������Ʋ��������ȵ����
��������:
	���������ƣ�������֮����"-"���ӣ�ÿ���Ƶ�ÿ���Կո�ָ���"-"����û�пո�
	�磺4 4 4 4-joker JOKER
���������
		����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬��Ȼ�Կո������
		��������ڱȽϹ�ϵ�����ERROR
����:
����:	4 4 4 4-joker JOKER
���:	joker JOKER
*/

/*
˼·���ַ���ƥ������   ������������map��<key,value> valueԽ������Խ�� 
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
				//���������10  10���ڴ��еĴ洢Ϊ��1����0����ռһ���ֽ�
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
	//���������С��ϵ 
	vector<string> arr = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "joker" };
	map<string, int> map;
	for (size_t i = 0; i < arr.size(); ++i){
		map[arr[i]] = i;
	}

	while (getline(cin, s)){
		//Ѱ��"-"���ַ�����λ��
		size_t pos = s.find("-");

		//�����������
		string left = s.substr(0, pos);
		string right = s.substr(pos + 1, s.size() - pos);
		
		//�ж��Ƶ����ࣺ����/����....
		int leftSize = 0, rightSize = 0;
		_size(left, leftSize);
		_size(right, rightSize);
	
		//��ͬ���͵��ƱȽ�
		if (leftSize == rightSize){
			//���������fun����ֵ���
			//��Ϊ����/����/����/ը��ֻ��Ҫ�Ƚ����һ���ַ�����
			//(�����������֮��ıȽϲ��������Ӻ���֮��ıȽ�)
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
				//��������֮��ıȽ�
				cout << "JOKER" << endl;
				continue;
			}
			if (leftSize == 1 || rightSize == 1){
				//���ź���֮��ıȽ�
				if (leftSize == -1||rightSize==-1){
					cout << "joker" << endl;
					continue;
				}
				else if (leftSize == 0 || rightSize == 0){
					cout << "JOKER" << endl;
					continue;
				}
			}
			//��ͬ���͵��ƱȽ�
			 if (leftSize == 6 || rightSize == 6){
				//ֻҪ��һ��Ϊ��ըֱ�������ը
				cout << "joker JOKER" << endl;
				continue;
			}
			//��ͬ������ �ų���ը ֻ��ը����� 
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

