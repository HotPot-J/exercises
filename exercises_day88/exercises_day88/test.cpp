#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ӿ���
һ�������ˮƽֵΪ�ö����Ա�еڶ���ˮƽֵ �μӱ�������3*n��ѡ��
һ������ˮƽֵ�ֱ�Ϊ3��3��3 �����ˮƽֵ��Ϊ3
һ������ˮƽֵ�ֱ�Ϊ3��2��3 �����ˮƽֵ��Ϊ3

�����6����Ա��Ϊ1 2 5 �� 5 5 8 ˮƽֵΪ2+5 = 7
                 2 5 8 �� 1 5 5 ˮƽֵ5+5 = 10
���ˮƽֵ��ߵ���ӷ���
��������:
	��һ��һ��������n
	�ڶ���3*n������
���:���ˮƽֵ�ܺ�	
*/

//˼·��̰���㷨 ����
//#include<iostream>
//#include<deque>
//#include<algorithm>
//using namespace std;
//int main(){
//	int n = 0;
//	int tmp = 0;
//	int res = 0;
//	deque<int> a;
//	cin >> n;
//	for (int i = 0; i < n * 3; ++i){
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	//���� ÿ��ѡ�����ʹδ�Ļ�����С�ĳ��� res+=�δ�� 
//	sort(a.begin(), a.end());
//	while (a.size() >= 3){
//		a.pop_back();//�������
//		res += a.back();//��¼ˮƽ
//		a.pop_back();//�����δ�
//		a.pop_front();//������С
//	}
//	cout << res << endl;
//	return 0;
//}

/*
���������ַ������ӵ�һ���ַ���ɾ���ڶ����ַ������е��ַ������磺
They are students��aeiou ɾ��֮��Thy r stdnts
*/
/*
˼·����ϣ��+string�е�erase��size_t pos,size_t n������(��posλ��ɾ��n���ַ�)
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
	string a;
	string b;
	getline(cin,a);
	getline(cin, b);
	unordered_map<char, bool> m;
	for (auto it : b){
		m[it] = true;
	}
	for (size_t i = 0; i < a.size(); ++i){
		if (m[a[i]]){
			a.erase(i, 1);
		}
	}
	cout << a << endl;
	return 0;
}