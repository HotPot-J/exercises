#define _CRT_SECURE_NO_WARNINGS 1

/*
1������������ţ�ͣ�
һ�黨������������Щͼ������һ��ֱ�ӿ��õ�С����������Ҳ��һЩͼ�������ڸ����Ļ�����
��С����������һ���ܴӻ������о����ܼ�������С��������
*/

/*
 ˼·�����Ӵ�  ��ָ�����ƥ�伴��
*/

#include<iostream>
#include<string>
using namespace std;

//int main(){
//	string str;
//	string tmp;
//	while (cin >> str >> tmp){
//		int len1 = str.size();
//		int len2 = tmp.size();
//		int j = 0, res = 0;
//		for (int i = 0; i < len1; ++i){
//			int k = i;
//			for (j = 0; j < len2; ++j){
//				if (k < len1&&str[k] == tmp[j]){
//					++k;
//				}
//				else{
//					break;
//				}
//			}
//			if (j == len2){
//				++res;
//				i = k-1;
//			}
//		}
//		cout << res << endl;
//	}
//	return 0;
//}

/*
2������������ţ�ͣ�
*/

/*
˼·: ����쳲�������...
*/

#include<iostream>
using namespace std;
int main(){
	//������Ŀ��Χ �ȴ�� 
	long long arr[81] = { 0 };
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i < 81; ++i){
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	int from = 0, to = 0;
	while (cin >> from >> to){
		long long res = 0;
		for (int i = from; i <= to; ++i){
			res += arr[i];
		}
		cout << res << endl;
	}
	return 0;
}