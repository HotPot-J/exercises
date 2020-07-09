#define _CRT_SECURE_NO_WARNINGS 1

/*
1、收件人列表 （牛客）
*/

/*
思路：字符串匹配问题
*/

#include<iostream>
#include<string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		cin.get();
		for (int i = 0; i<n; i++)
		{
			getline(cin, s);
			if (i != n - 1)
			{
				if (s.find(',') != string::npos || s.find(' ') != string::npos)
					cout << '\"' << s << '\"' << ',' << ' ';
				else
					cout << s << ',' << ' ';
			}
			else
			{
				if (s.find(',') != string::npos || s.find(' ') != string::npos)
					cout << '\"' << s << '\"' << endl;
				else
					cout << s << endl;
			}
		}
	}
	return 0;
}

/*
养兔子 （牛客）
*/

/*
思路：斐波那契的实质
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	long long arr[100];
	arr[1] = 1;
	arr[2] = 2;
	while (cin >> n){
		for (int i = 3; i <= n; i++){
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		cout << arr[n] << endl;
	}
}