#define _CRT_SECURE_NO_WARNINGS 1

/*
1������������
1.��c/c++ת��java�ĳ���Ա��һ��ʼ�ϰ�ߵľ���������ʽ�ĸı䡣c���Է��ʹ���»��߷ָ�
������ʣ�����"hello_world";��java�����һ���շ������������׸������⣬���е��ʵ�����ĸ
��д��helloWorld�����������ĳ���Ա���Զ�ת��������

����������
	��������������ݡ�
	ÿ����һ�У�����һ��c���Է��ı�����ÿ�����������Ȳ�����100

���������
	��Ӧÿһ�����ݣ������������Ӧ���շ�������
*/

/*
˼·:�ַ����Ĵ���
	����_ֱ��������Ȼ�󽫵�ǰ�ַ�ת��д
	�ռ临�Ӷ�O��2��
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
2�����ʵ���

��Ŀ������
	���ַ��������е��ʽ��е��š�
	˵����
		1.ÿ����������26����д��СдӢ����ĸ����;
		2.�ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ����
		3.Ҫ���ź�ĵ��ʼ����һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж���������
		����ת����Ҳֻ�������һ���ո�����
		4.ÿ�������20����ĸ
	��������:
		����һ���Կո����ָ��ľ���
	���������
		������ӵ�����

*/

/*
˼·:
	1.�Ƚ������ַ��������ٽ��������򼴿�
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
		//�Ƚ��ָ���������
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
		//��תÿ����ĸ
		char* s = (char*)b.c_str();
		char* top = s, *tail = s;
		while (*tail){
			if (*tail == ' '){
				_reverse(s, top, tail - 1);
				++tail;
				top = tail;
			}
			else if (*(tail + 1) == '\0'){
				//���һ������
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

