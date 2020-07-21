#define _CRT_SECURE_NO_WARNINGS 1

/*
1、骆驼命名法
1.从c/c++转到java的程序员，一开始最不习惯的就是命名方式的改变。c语言风格使用下划线分割
多个单词，例如"hello_world";而java则采用一种驼峰命名法：除首个单词外，所有单词的首字母
大写：helloWorld。请你帮可怜的程序员们自动转换变量名

输入描述：
	输入包含多组数据。
	每数据一行，包含一个c语言风格的变量。每个变量名长度不超过100

输出描述：
	对应每一组数据，输出变量名响应的驼峰命名法
*/

/*
思路:字符串的处理
	遇到_直接跳过，然后将当前字符转大写
	空间复杂度O（2）
*/

#include<iostream>
#include<string>
using namespace std;

//int main(){
//	string a;
//	while (cin>>a){
//		string b;
//		int len = a.size();
//		for (int i = 0; i < len; ++i){
//			if (a[i] == '_'){
//				++i;
//				a[i] = toupper(a[i]);
//			}
//			b += a[i];
//		}
//		cout << b << endl;
//	}
//	return 0;
//}

/*
2、单词倒排

题目描述：
	对字符串中所有单词进行倒排。
	说明：
		1.每个单词是以26个大写或小写英文字母构成;
		2.非构成单词的字符均视为单词间隔符
		3.要求倒排后的单词间隔以一个空格表示；如果原字符串中相邻单词间有多个间隔符，
		倒排转换后也只允许出现一个空格间隔符
		4.每个单词最长20个字母
	输入描述:
		输入一行以空格来分隔的句子
	输出描述：
		输出句子的逆序

*/

/*
思路:
	1.先将整个字符串逆序，再将单词逆序即可
*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void _reverse(char* s,char* top,char* tail){
	while (top < tail){
		swap(*top,*tail);
		++top;
		--tail;
	}
}
int main(){
	string a;
	while (getline(cin, a)){
		//先将分隔符处理完
		string b;
		auto it = a.begin();
		while (it != a.end()){
			int flag = 0;
			while (!isalpha(*it)){
				++it;
				flag = 1;
			}
			if (flag){
				b += " ";
				b += *it;
			}
			else{
				b += *it;
			}
			++it;
		}
		reverse(b.begin(), b.end());
		//翻转每个字母
		char* s = (char*)b.c_str();
		char* top = s, *tail = s;
		while (*tail){
			if (*tail == ' '){
				_reverse(s, top, tail - 1);
				++tail;
				top = tail;
			}
			else if (*(tail + 1) == '\0'){
				//最后一个单词
				_reverse(s, top, tail);
				++tail;
			}
			else{
				++tail;
			}
		} 
		printf("%s\n", s);
	}
	return 0;
}

