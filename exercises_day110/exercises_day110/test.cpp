#define _CRT_SECURE_NO_WARNINGS 1

/*
1��С�׾���������������Ϸ����һ��������һ�������������Ϸ�����Ľ�ɫ��ʼ����ֵΪa����
��������һ��ʱ���ڣ�����������n�����ÿ������ķ�����Ϊb1��b2��b3...bn.��������Ĺ�
�������biС�ڵ���С�׵ĵ�ǰ����ֵc����ô���������ɴ�ܹ������ʹ�Լ�������ֵ����bi��
���bi����c����ô��Ҳ�ܴ�ܹ������������ֻ������bi��c�����Լ������ô�������ˣ���
һϵ�еĶ�����С�׵���������ֵΪ���٣�
����������
	����ÿ�����ݣ���һ������������n(1<=n<100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ
	�ڶ���n��������b1��b2...bn(1<=bi<=n)��ʾÿ������ķ�����
�������:
	����ÿ�����ݣ����һ�У�ÿ�н�����һ����������ʾС�׵���������ֵ
����:
	3 50
    50 105 200
���:
	110
*/
/*
˼·:շת��������Լ��
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//���Լ��
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
2���ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
���룺����һ���ǿ��ַ���
��������һ����ֻ����һ�ε��ַ���������������-1
*/

/*
˼·:��ϣ 
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
˼·2�����������ҵ�ǰ�ַ������������ҵ�ǰ�ַ���������ͬһ�±� ��˵��ֻ��һ�����ַ�
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