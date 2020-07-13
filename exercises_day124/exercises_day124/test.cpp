#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
/*
1、数据库连接池
web系统通常会频繁的访问数据库，如果每次访问都创建新连接，性能可能会很差，为了提高
性能，架构师决定复用已经创建的连接，当收到请求，并且连接池中没有剩余可用的连接时，
系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。
现在提供你处理请求的日志，请分析一下连接池最多需要创建多少个连接。
输入描述: 
  输入包含多组数据，每组第一行包含一个正整数n（[1,1000]）,表示请求的数量。
  紧接着n行，每行包含一个请求编号id(a,b,c......,z)和操作（connect或disconnect）
输出描述:
	对应每一组数据，输出连接池最多需要创建多少个连接

输入描述：
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
输出描述：
2
*/

/*
思路：做好日志和数据池的统计即可，有可用的就出--pool，没有就创建++res，用完了
就入池++pool
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
				//建立连接请求
				if (pool){
					--pool;
				}
				else{
					//建立一次连接
					++res;
				}
			}
			else{
				//建立断开 断开直接放进pool就行
				++pool;
			}
		}
		cout << res << endl;
	}
	return 0;
}


/*
2、mkdir（牛客）
工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录
"/usr/local/bin"，就需要依次创建/usr、/usr/local、/usr/local/bin。
好在。Linux下mkdir提供了强大的-p选项，只要一条命令mkdir -p /usr/local/bin，就能
自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的mkdir -p命令
输入描述:
	输入包含多组数据，每组数据第一行为一个正整数n([1，1024])
	紧接着n行，每行包含一个带创建的目录名，目录名仅由数字和字母组成，长度不超过200
输出描述：
	对应每一组数据，输出相应的、按照字典顺序排序的mkdir -p命令
	每组数据之后输出一个空行作为分隔

输入：
	3
	/a
	/a/b
	/a/b/c
	
输出:
	mkdir -p /a/b/c
*/

/*
思路:将输入放进数组中，让后sort排序,
1.如果前串==后串 输出前串不必输出
2.如果前传是串的一部分，前串不必输出
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