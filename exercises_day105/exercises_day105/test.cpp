#define _CRT_SECURE_NO_WARNINGS 1

/*
1��ͳ��ÿ�������ӵ�����
��һֻ���ӣ��ӳ��������������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ����
����һֻ���ӣ��������Ӷ���������ÿ�������ӵ�����Ϊ����?
����: �·�
���������
*/

/*
˼·: һ�£�1 ���£�1 ���£� 2  ��:3  �壺5 ����:8...
�ܽ����Ϊһ��쳲��������� �ݹ鼴��
*/
#include<iostream>
#include<vector>
using namespace std;
////�ݹ��
//int rabbit1(int mouth){
//	if (mouth == 1 || mouth == 2){
//		return 1;
//	}
//	return rabbit1(mouth - 2) + rabbit1(mouth - 1);
//}
//���ư� �����ƽϵݹ�Ч�ʸ��� �����˺ܶ��ظ����㣩
int rabbit2(int mouth){
	vector<int> arr;
	arr.push_back(1); arr.push_back(1);
	if ((mouth)-1 <= 1){
		return 1;
	}
	int i = 2;
	while (i<mouth){
		arr.push_back(arr[i - 2] + arr[i - 1]);
		++i;
	}
	return arr[i-1];
}

//int main(){
//	int m = 0;
//	while (cin >> m){
//		cout<<rabbit2(m)<<endl;
//	}
//	return 0;
//}

/*
2���ַ���ͨ���
��Ŀ����:
	�ڼ�����У�ͨ�����һ�������﷨���㷺�����ļ����������ݿ⡢������ʽ������Ҫ��
	��λʵ���ַ���ͨ������㷨��
	Ҫ��
	ʵ������2��ͨ�����
	*:ƥ��0�����ϵ��ַ�(�ַ���Ӣ�ĺ�����0-9��ɣ������ִ�Сд����ͬ)
	?:ƥ��1���ַ�

	���룺
		ͨ������ʽ��
		һ���ַ���
	�����
		����ƥ��Ľ������ȷ���true �������false
����:
���룺
	te��t*.*
	txt12.xls
�����
	false
*/

/*
˼·һ:���������ַ����Ƚϵı����� �����Ͼ���˫ָ�������� ����ƥ�伴�� ��Ҫע�����?ƥ������һ���ַ� *��ƥ��0�������ַ�

*/
#include<iostream>
#include<string>
using namespace std;

void _compare(string a, string b){
	int i = 0, j = 0,flag = 0, aSize = a.size(), bSize = b.size();
	while (i < aSize||j < bSize){
		 if (i<aSize&&a[i] == '*'){
			++i;
			flag = 1;//��������һ��Ϊ*
		}
		 else if (a[i] == '?' || a[i] == b[j]){
			 //?�����κ���ĸ ֱ������ƥ��ɹ�
			 ++i;
			 ++j;
		 }
		 else if (flag){
			 while (a[i] != b[j]){
				 ++j;
			 }
			 flag = 0;
		 }
		else {
			cout << "false" <<endl;
			break;
		}
		if (i == aSize && j == bSize){
			//ͬʱ�ߵ���ͷ����ƥ��ɹ�
			cout << "true" << endl;
			break;
		}
	}
}


/*˼·�����ݹ���
1.������?�ʺŻ����ַ���� ͬʱ������һ��
2.������*
	*ƥ��0��||*ƥ��һ��||*ƥ����
*/

int main(){
	string a, b;
	while (cin >> a >> b){
		_compare(a, b);
	}
	return 0;
}