#define _CRT_SECURE_NO_WARNINGS 1

/*
1��A,B,C�������Ǻ����ѣ�ÿ�������ﶼ��һЩ�ǹ������ǲ�֪������ÿ�������Ͼ����ж��ٸ�
�ǹ�����������Ϣ:
	A-B,B-C,A+B,B+C���ĸ���ֵ��ÿ����ĸ����ÿ����ӵ�е��ǹ�����������Ҫͨ�����ĸ���ֵ
	�����ÿ���������ж��ٸ��ǹ�����A,B,C ���ﱣ֤����ֻ��һ������������������

��������:
	����Ϊһ�У�һ���ĸ��������ֱ�ΪA-B,B-C,A+B,B+C ��-30��30�ı����䣩
�������:
	���Ϊһ�У�����������������A,B,C����˳�����A,B,C�����ھ����No
���ӣ�	1 -2 3 4
		2 1 3
*/

//˼·����Ԫһ�η�����

#include<iostream>
#include<vector>
using namespace std;
void fun1(vector<int>& arr){
	vector<int> res;
	int A = (arr[0] + arr[2])/2;
	int B = (arr[1] + arr[3]) / 2;
	int C = 0;
	if ((A - B) == arr[0] && (A + B) == arr[2]){
		//֤����A B���ϵ��������
		res.push_back(A);
		res.push_back(B);
		//֤��C
		C = (arr[3] - arr[1]) / 2;
		if (B - C == arr[1] && B + C == arr[3]){
			res.push_back(C);
			for (int i = 0; i < 3; ++i){
				cout << res[i] << " ";
			}
		}
		else{
			cout << "No" << endl;
		}
	}
	else{
		cout << "No" << endl;
	}
}
//int main(){
//	vector<int> arr;
//	int tmp = 0;
//	for (int i = 0; i < 4; ++i){
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	fun1(arr);
//	return 0;
//}

/*
2������һ��ʮ������M���Լ���Ҫת��������N����ʮ������Mת��ΪN������
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int arr[2] = {0,0};
	string res, tmp = "0123456789ABCDEF";
	for (int i = 0; i < 2; ++i){
		cin >> arr[i];
	}
	if (arr[0] == 0){
		cout << "0" << endl;
	}
	else{
		while (arr[0]){
			if (arr[0] < 0){
				arr[0] = -arr[0];
				cout << "-";
			}
			res = tmp[arr[0] % arr[1]] + res;
			arr[0] /= arr[1];
		}
	}
	cout << res;
	return 0;
}

