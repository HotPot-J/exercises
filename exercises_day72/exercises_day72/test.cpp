#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//int main(){
//	int n = 0;
//	int flag = 1;
//	cin >> n;
//	for (int i = 10; i<n; ++i){
//		int tmp = i;
//		flag = 1;
//		for (int j = 2; j <= (tmp / 2); ++j){
//			if (i%j == 0){
//				flag = 0;
//				break;
//			}
//		}
//		if (flag){
//			if (i<100 && i % 10 == 1){
//				cout << i << " ";
//			}
//			else if (i<1000 && i % 100 == 1){
//				cout << i << " ";
//			}
//			else if (i<10000 && i % 1000 == 1){
//				cout << i << " ";
//			}
//		}
//	}
//	return 0;
//}

class Solution {
public:

	string change(string number) {
		char* top = (char*)number.c_str();
		char* tail = top + (number.size() - 1);
		while (top < tail){
			while (*top % 2 != 0){
				++top;
			}
			while (*tail%2!=0){
				--tail;
			}
			if (top < tail){
				swap(*top, *tail);
			}
			++top;
			--tail;
		}
		return number;
	}
};
int main(){
	Solution a;
	string c("1234");
	string res = a.change(c);
	return 0;
}