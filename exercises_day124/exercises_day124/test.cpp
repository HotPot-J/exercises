#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1�����ݿ����ӳ�
webϵͳͨ����Ƶ���ķ������ݿ⣬���ÿ�η��ʶ����������ӣ����ܿ��ܻ�ܲΪ�����
���ܣ��ܹ�ʦ���������Ѿ����������ӣ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��
ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�
�����ṩ�㴦���������־�������һ�����ӳ������Ҫ�������ٸ����ӡ�
��������: 
  ��������������ݣ�ÿ���һ�а���һ��������n��[1,1000]��,��ʾ�����������
  ������n�У�ÿ�а���һ��������id(a,b,c......,z)�Ͳ�����connect��disconnect��
�������:
	��Ӧÿһ�����ݣ�������ӳ������Ҫ�������ٸ�����

����������
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
���������
2
*/

/*
˼·��������־�����ݳص�ͳ�Ƽ��ɣ��п��õľͳ�--pool��û�оʹ���++res��������
�����++pool
*/

#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		deque<string> log;
		int  pool = 0, res = 0;
		string tmp;
		cin.ignore();
		for (int i = 0; i < n; ++i){
			getline(cin, tmp);
			log.push_back(tmp);
		}
		size_t len = log.size();
		for (size_t i = 0; i < len; ++i){
			if (log[i][2] == 'c'){
				//������������
				if (pool){
					--pool;
				}
				else{
					//����һ������
					++res;
				}
			}
			else{
				//�����Ͽ� �Ͽ�ֱ�ӷŽ�pool����
				++pool;
			}
		}
		cout << res << endl;
	}
	return 0;
}


/*
2��mkdir��ţ�ͣ�
�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼
"/usr/local/bin"������Ҫ���δ���/usr��/usr/local��/usr/local/bin��
���ڡ�Linux��mkdir�ṩ��ǿ���-pѡ�ֻҪһ������mkdir -p /usr/local/bin������
�Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ��mkdir -p����
��������:
	��������������ݣ�ÿ�����ݵ�һ��Ϊһ��������n([1��1024])
	������n�У�ÿ�а���һ����������Ŀ¼����Ŀ¼���������ֺ���ĸ��ɣ����Ȳ�����200
���������
	��Ӧÿһ�����ݣ������Ӧ�ġ������ֵ�˳�������mkdir -p����
	ÿ������֮�����һ��������Ϊ�ָ�

���룺
	3
	/a
	/a/b
	/a/b/c
	
���:
	mkdir -p /a/b/c
*/

/*
˼·:������Ž������У��ú�sort����,
1.���ǰ��==�� ���ǰ���������
2.���ǰ���Ǵ���һ���֣�ǰ���������
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n = 0;
	while (cin >> n){
		cin.ignore();
		vector<string> arr;
		string tmp;
		for (int i = 0; i < n; ++i){
			getline(cin, tmp);
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n; ++i){
			if (i<n-1&&arr[i] == arr[i + 1]){
				arr[i] = '\0';
			}
			if (i<n-1&&
				arr[i].size() < arr[i + 1].size() &&
				arr[i] == arr[i + 1].substr(0, arr[i].size()) &&
				arr[i + 1][arr[i].size()] == '/'){
				arr[i] = '\0';
			}
		}
		for (int i = 0; i < n; ++i){
			if (arr[i][0]){
				cout << "mkdir -p " << arr[i] << endl;
			}
		}
		cout << endl;
	
	}
	return 0;
}